/* Copyright (c) 2012, 2020, Oracle and/or its affiliates. All rights reserved.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License, version 2.0,
   as published by the Free Software Foundation.

   This program is also distributed with certain software (including
   but not limited to OpenSSL) that is licensed under separate terms,
   as designated in a particular file or component or in included license
   documentation.  The authors of MySQL hereby grant you an additional
   permission to link the program and your derivative works with the
   separately licensed software that they have included with MySQL.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License, version 2.0, for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA */

#ifndef SIMSET_H
#define SIMSET_H

#include <stddef.h>
#ifndef XCOM_STANDALONE
#include "my_compiler.h"
#endif
#include "xcom/x_platform.h"

struct linkage;
typedef struct linkage linkage;

struct linkage {
  unsigned int type; /* Not strictly necessary, used for rudimentary run time
                        type check */
  linkage *suc;      /* Next in list */
  linkage *pred;     /* Previous in list */
};

extern char *dbg_linkage(linkage *self); /* Debug link */

/* fwd decl，从链表中删除self节点，self节点变为前序后后继节点都指向自己的节点 */
static inline linkage *link_out(linkage *self); /* Remove link from list */

/* Forward iterator */
/* 当前节点开始，向后遍历，因为是双向循环链表，总会回到自身 */
#define FWD_ITER(head, type, action)                      \
  {                                                       \
    linkage *p = link_first(head);                        \
    while (p != (head)) {                                 \
      linkage *_next = link_first(p);                     \
      {                                                   \
        type *link_iter = (type *)p;                      \
        (void)link_iter;                                  \
        action;                                           \
      } /* Cast to void avoids unused variable warning */ \
      p = _next;                                          \
    }                                                     \
  }

/* Reverse iterator */
#define REV_ITER(head, type, action)                      \
  {                                                       \
    linkage *p = link_last(head);                         \
    while (p != (head)) {                                 \
      linkage *_next = link_last(p);                      \
      {                                                   \
        type *link_iter = (type *)p;                      \
        (void)link_iter;                                  \
        action;                                           \
      } /* Cast to void avoids unused variable warning */ \
      p = _next;                                          \
    }                                                     \
  }

/* Get containing struct from pointer to member and type */
#define container_of(ptr, type, member) \
  ((type *)(((char *)(ptr)) - offsetof(type, member)))

#define NULL_TYPE 0xdefaced

#ifdef USE_LINK_SANITY_CHECK
#define LINK_SANITY_CHECK(x) \
  {                          \
    assert((x)->suc);        \
    assert((x)->pred);       \
  }
#define TYPE_SANITY_CHECK(x, y) \
  { assert((x)->type == (y)->type); }
#else
#define LINK_SANITY_CHECK(x)
#define TYPE_SANITY_CHECK(x, y)
#endif
/* 将self链接到s的前面 */
#define link_into(self, s) link_precede(self, s)

#define TYPE_HASH(x) 0

/* purecov: begin deadcode */
static inline linkage *link_first(linkage *self) { return self->suc; }

static inline linkage *link_last(linkage *self) { return self->pred; }
/* purecov: end */
static inline linkage *link_extract_first(linkage *self) {
  return link_out(self->suc);
}

static inline linkage *link_extract_last(linkage *self) {
  return link_out(self->pred);
}

static inline int link_empty(linkage *self) { return self == self->suc; }

static inline linkage *link_init(linkage *self, unsigned int type) {
  /* XDBG("%s ",__func__); */
  self->type = type;
  self->suc = self->pred = self;
  LINK_SANITY_CHECK(self);
  return self;
}

// 从链表中删除self节点，self节点变为前序后后继节点都指向自己的节点
static inline linkage *link_out(linkage *self) {
  /* XDBG("%s ",__func__); */
  if (!link_empty(self)) {
    TYPE_SANITY_CHECK(self, self->suc);
    TYPE_SANITY_CHECK(self, self->pred);
    self->suc->pred = self->pred;
    self->pred->suc = self->suc;
    self->suc = self->pred = self;
  }
  LINK_SANITY_CHECK(self);
  return self;
}

// 在双向链表中ptr后插入self
static inline void link_follow(linkage *self, linkage *ptr) {
  /* XDBG("%s ",__func__); */
  link_out(self); // 首先从self的原链表中删除自身
  if (ptr) {
    TYPE_SANITY_CHECK(self, ptr);
    LINK_SANITY_CHECK(ptr);
    self->pred = ptr;
    self->suc = ptr->suc;
    self->suc->pred = ptr->suc = self;
    LINK_SANITY_CHECK(self);
  }
}

// 在ptr的前面插入self节点
static inline void link_precede(linkage *self, linkage *ptr) {
  /* XDBG("%s ",__func__); */
  link_out(self);
  if (ptr) {
    TYPE_SANITY_CHECK(self, ptr);
    LINK_SANITY_CHECK(ptr);
    self->suc = ptr;
    self->pred = ptr->pred;
    self->pred->suc = ptr->pred = self;
    LINK_SANITY_CHECK(self);
  }
}

/* purecov: begin deadcode */
/* 用于链表节点计数 */
static inline int cardinal(linkage *self) {
  int n = 0;
  FWD_ITER(self, linkage, n++);
  return n;
}
/* purecov: end */

#endif

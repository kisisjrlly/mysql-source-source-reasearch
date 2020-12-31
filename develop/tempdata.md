


+---------------------------+----------------------+--------------------------------------+-----------------------------+----------------------------+--------------------------+------------------------------------+-------------------------------------------+-----------------------------------------+--------------------------------------------+-----------------------------------+-----------------------------------+-----------------------------------+
| CHANNEL_NAME              | VIEW_ID              | MEMBER_ID                            | COUNT_TRANSACTIONS_IN_QUEUE | COUNT_TRANSACTIONS_CHECKED | COUNT_CONFLICTS_DETECTED | COUNT_TRANSACTIONS_ROWS_VALIDATING | TRANSACTIONS_COMMITTED_ALL_MEMBERS        | LAST_CONFLICT_FREE_TRANSACTION          | COUNT_TRANSACTIONS_REMOTE_IN_APPLIER_QUEUE | COUNT_TRANSACTIONS_REMOTE_APPLIED | COUNT_TRANSACTIONS_LOCAL_PROPOSED | COUNT_TRANSACTIONS_LOCAL_ROLLBACK |
+---------------------------+----------------------+--------------------------------------+-----------------------------+----------------------------+--------------------------+------------------------------------+-------------------------------------------+-----------------------------------------+--------------------------------------------+-----------------------------------+-----------------------------------+-----------------------------------+
| group_replication_applier | 16073955251217463:13 | 69511060-3627-11eb-9fad-70b5e831c9f8 |                           0 |                          1 |                        0 |                                  1 | aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-49 | aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:49 |                                          0 |                                 1 |                                 0 |                                 0 |
| group_replication_applier | 16073955251217463:13 | 6f2ca203-3627-11eb-8cd9-70b5e831c9f8 |                           0 |                          2 |                        0 |                                  1 | aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-49 | aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:49 |                                          0 |                                 5 |                                 0 |                                 0 |
| group_replication_applier | 16073955251217463:13 | 74ff0bf0-3627-11eb-a7bf-70b5e831c9f8 |                           0 |                          2 |                        0 |                                  1 | aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-49 | aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:49 |                                          0 |                                 5 |                                 2 |                                 0 |
+---------------------------+----------------------+--------------------------------------+-----------------------------+----------------------------+--------------------------+------------------------------------+-------------------------------------------+-----------------------------------------+--------------------------------------------+-----------------------------------+-----------------------------------+-----------------------------------+



### Group_member_info_manager更新bt

Thread 48 "mysqld" hit Breakpoint 3, Group_member_info_manager::update (
    this=0x7fff301484b0, new_members=0x7fff60ff8410)
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/src/member_info.cc:982
982         vector<Group_member_info *> *new_members) {
(gdb) bt
#0  Group_member_info_manager::update (this=0x7fff301484b0, 
    new_members=0x7fff60ff8410)
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/src/member_info.cc:982
#1  0x00007fffe030fee2 in Plugin_gcs_events_handler::update_group_info_manager (this=0x7fff3011f8b0, new_view=..., 
    exchanged_data=std::vector of length 2, capacity 2 = {...}, 
    is_joining=false, is_leaving=false)
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/src/gcs_event_handlers.cc:828
#2  0x00007fffe030f1c9 in Plugin_gcs_events_handler::on_view_changed (
    this=0x7fff3011f8b0, new_view=..., 
    exchanged_data=std::vector of length 2, capacity 2 = {...})
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/src/gcs_event_handlers.cc:668
#3  0x00007fffe0460acd in Gcs_xcom_control::install_view (
    this=0x7fff30117b40, new_view_id=0x7fff2c005c10, group=..., 
    states=0x7fff300a7490, total=0x7fff300a7400, left=0x7fff300a7430, 
    join=0x7fff300a7460, error_code=Gcs_view::OK)
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/libmysqlgcs/src/bindings/xcom/gcs_xcom_control_interface.cc:1767
#4  0x00007fffe0460435 in Gcs_xcom_control::process_control_message (
    this=0x7fff30117b40, msg=0x7fff09e7b3c0, 
    maximum_supported_protocol_version=Gcs_protocol_version::V2, 
    used_protocol_version=Gcs_protocol_version::V2)
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/libmysqlgcs/src/bindings/xcom/gcs_xcom_control_interface.cc:1665
#5  0x00007fffe03ec22f in do_cb_xcom_receive_data_state_exchange (
    packet=..., xcom_nodes=..., xcom_communication=..., xcom_control=...)
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/libmysqlgcs/src/bindings/xcom/gcs_xcom_interface.cc:1265
#6  0x00007fffe03ec749 in do_cb_xcom_receive_data (message_id=..., 
    xcom_nodes_raw_ptr=0x7fff0a2eac30, cache_last_removed=..., size=529, 
    data_raw_ptr=0x7fff09bd1980 "\240\033\275\t\377\177")
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/libmysqlgcs/src/bindings/xcom/gcs_xcom_interface.cc:1364
#7  0x00007fffe03f82c9 in Data_notification::do_execute (
    this=0x7fff099c70f0)
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/libmysqlgcs/src/bindings/xcom/gcs_xcom_notification.cc:80
#8  0x00007fffe03fa463 in Parameterized_notification<false>::operator() (
    this=0x7fff099c70f0)
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/libmysqlgcs/src/bindings/xcom/gcs_xcom_notification.h:225
#9  0x00007fffe03f8cfa in Gcs_xcom_engine::process (this=0x7fff300bcef0)
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/libmysqlgcs/src/bindings/xcom/gcs_xcom_notification.cc:219
#10 0x00007fffe03f889f in process_notification_thread (
    ptr_object=0x7fff300bcef0)
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/libmysqlgcs/src/bindings/xcom/gcs_xcom_notification.cc:156
#11 0x000055555a809a8c in pfs_spawn_thread (arg=0x7fff30116b50)
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/storage/perfschema/pfs.cc:2880
#12 0x00007ffff7bbb6db in start_thread (arg=0x7fff60ff9700)
    at pthread_create.c:463
#13 0x00007ffff613871f in clone ()
    at ../sysdeps/unix/sysv/linux/x86_64/clone.S:95


### 新加入节点时，seconddary节点收到广播状态消息bt

    Thread 80 "mysqld" hit Breakpoint 1, 0x00007fffe02b5790 in Gcs_xcom_state_exchange::broadcast_state(Gcs_xcom_view_identifier const&, std::vector<std::unique_ptr<Gcs_message_data, std::default_delete<Gcs_message_data> >, std::allocator<std::unique_ptr<Gcs_message_data, std::default_delete<Gcs_message_data> > > >&)@plt ()
   from /usr/local/mysql/lib/plugin/group_replication.so
(gdb) bt
#0  0x00007fffe02b5790 in Gcs_xcom_state_exchange::broadcast_state(Gcs_xcom_view_identifier const&, std::vector<std::unique_ptr<Gcs_message_data, std::default_delete<Gcs_message_data> >, std::allocator<std::unique_ptr<Gcs_message_data, std::default_delete<Gcs_message_data> > > >&)@plt ()
   from /usr/local/mysql/lib/plugin/group_replication.so
#1  0x00007fffe04861ff in Gcs_xcom_state_exchange::state_exchange (this=0x7fff38028460, 
    configuration_id=..., 
    total=std::vector of length 3, capacity 4 = {...}, left=std::vector of length 0, capacity 0, 
    joined=std::vector of length 1, capacity 1 = {...}, 
    exchangeable_data=std::vector of length 1, capacity 1 = {...}, current_view=0x7fff24005d80,                                               -
    group=0x7fff60ff89d0, local_info=..., > to quit--- 
    xcom_nodes=...)
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/libmysqlgcs/src/bindings/xcom/gcs_xcom_state_exchange.cc:482
#2  0x00007fffe045f9cc in Gcs_xcom_control::xcom_receive_global_view (this=0x7fff01a66650, config_id=..., 
    message_id=..., xcom_nodes=0x7ffef855b910, 
    same_view=false, max_synode=...)
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/libmysqlgcs/src/bindings/xcom/gcs_xcom_control_interface.cc:1536
#3  0x00007fffe03ed1be in do_cb_xcom_receive_global_view (config_id=..., message_id=..., 
    xcom_nodes=0x7ffef855b910, event_horizon=10, 
    max_synode=...)
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/-lugin/group_replication/libmysqlgcs/src/bindings/xcom/gcs_xcom_interface.cc:1519
#4  0x00007fffe03f84f1 in Global_view_notification::do_execute (this=0x7fff01d65340)
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/libmysqlgcs/src/bindings/xcom/gcs_xcom_notification.cc:106
#5  0x00007fffe03fa463 in Parameterized_notification<false>::operator() (this=0x7fff01d65340)
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/libmysqlgcs/src/bindings/xcom/gcs_xcom_notification.h:225
#6  0x00007fffe03f8cfa in Gcs_xcom_engine::process (
    this=0x7fff340012c0)
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/libmysqlgcs/src/bindings/xcom/gcs_xcom_notification.cc:219      -
#7  0x00007fffe03f889f in process_notification_thread- 
    (ptr_object=0x7fff340012c0)
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/libmysqlgcs/src/bindings/xcom/gcs_xcom_notification.cc:156
#8  0x000055555a809a8c in pfs_spawn_thread (
    arg=0x7fff380d2910)
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/storage/perfschema/pfs.cc:2880
#9  0x00007ffff7bbb6db in start_thread (
    arg=0x7fff60ff9700) at pthread_create.c:463
#10 0x00007ffff613871f in clone ()
    at ../sysdeps/unix/sysv/linux/x86_64/clone.S:95


### Gcs_xcom_state_exchange::broadcast_state

#0  0x00007fffe02b5790 in Gcs_xcom_state_exchange::broadcast_state(Gcs_xcom_view_identifier const&, std::vector<std::unique_ptr<Gcs_message_data, std::default_delete<Gcs_message_data> >, std::allocator<std::unique_ptr<Gcs_message_data, std::default_delete<Gcs_message_data> > > >&)@plt () from /usr/local/mysql/lib/plugin/group_replication.so
#1  0x00007fffe04861ff in Gcs_xcom_state_exchange::state_exchange (this=0x7fff383eda70, configuration_id=..., 
    total=std::vector of length 2, capacity 2 = {...}, left=std::vector of length 1, capacity 1 = {...}, 
    joined=std::vector of length 0, capacity 0, exchangeable_data=std::vector of length 1, capacity 1 = {...}, 
    current_view=0x7fff340030c0, group=0x7fff60ff89d0, local_info=..., xcom_nodes=...)
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/libmysqlgcs/src/bindings/xcom/gcs_xcom_state_exchange.cc:482
#2  0x00007fffe045f9cc in Gcs_xcom_control::xcom_receive_global_view (this=0x7fff0400b120, config_id=..., message_id=..., 
    xcom_nodes=0x7ffef9a73a50, same_view=false, max_synode=...)
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/libmysqlgcs/src/bindings/xcom/gcs_xcom_control_interface.cc:1536
#3  0x00007fffe03ed1be in do_cb_xcom_receive_global_view (config_id=..., message_id=..., xcom_nodes=0x7ffef9a73a50, 
    event_horizon=10, max_synode=...)
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/libmysqlgcs/src/bindings/xcom/gcs_xcom_interface.cc:1519
#4  0x00007fffe03f84f1 in Global_view_notification::do_execute (this=0x7ffef9a7aec0)
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/libmysqlgcs/src/bindings/xcom/gcs_xcom_notification.cc:106
#5  0x00007fffe03fa463 in Parameterized_notification<false>::operator() (this=0x7ffef9a7aec0)
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/libmysqlgcs/src/bindings/xcom/gcs_xcom_notification.h:225
#6  0x00007fffe03f8cfa in Gcs_xcom_engine::process (this=0x7fff15a90950)
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/libmysqlgcs/src/bindings/xcom/gcs_xcom_notification.cc:---Type <return> to continue, or q <return> to quit---
219
#7  0x00007fffe03f889f in process_notification_thread (ptr_object=0x7fff15a90950)
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/libmysqlgcs/src/bindings/xcom/gcs_xcom_notification.cc:156
#8  0x000055555a809a8c in pfs_spawn_thread (arg=0x7fff383e9eb0)
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/storage/perfschema/pfs.cc:2880
#9  0x00007ffff7bbb6db in start_thread (arg=0x7fff60ff9700) at pthread_create.c:463
#10 0x00007ffff613871f in clone () at ../sysdeps/unix/sysv/linux/x86_64/clone.S:95


### 主节点退出时，即将成为secondary的节点上pick_primary_member bt

Thread 70 "mysqld" hit Breakpoint 1, 0x00007fffe02c7c40 in Primary_election_handler::pick_primary_member(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >&, std::vector<Group_member_info*, std::allocator<Group_member_info*> >*)@plt ()
   from /usr/local/mysql/lib/plugin/group_replication.so
(gdb) bt
#0  0x00007fffe02c7c40 in Primary_election_handler::pick_primary_member(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >&, std::vector<Group_member_info*, std::allocator<Group_member_info*> >*)@plt ()
   from /usr/local/mysql/lib/plugin/group_replication.so
#1  0x00007fffe0395c94 in Primary_election_handler::execute_primary_election (this=0x7fff119df860, 
    primary_uuid="", mode=DEAD_OLD_PRIMARY, 
    notification_ctx=0x7fff38148628)
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/src/plugin_handlers/primary_election_invocation_handler.cc:118
#2  0x00007fffe030fbf5 in Plugin_gcs_events_handler::handle_leader_election_if_needed (this=0x7fff381485e0, 
    election_mode=DEAD_OLD_PRIMARY, suggested_primary="")
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/src/gcs_event_handlers.cc:791
#3  0x00007fffe030f4b3 in Plugin_gcs_events_handler::on_view_changed (this=0x7fff381485e0, new_view=..., 
    exchanged_data=std::vector of length 2, capacity 2 = {...})
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/src/gcs_event_handlers.cc:712
#4  0x00007fffe0460acd in Gcs_xcom_control::install_view
    (this=0x7fff11a6b020, new_view_id=0x7fff2c098a40, 
---Type <return> to continue, or q <return> to quit---
    group=..., states=0x7fff380a7460, 
    total=0x7fff380a73d0, left=0x7fff380a7400, 
    join=0x7fff380a7430, error_code=Gcs_view::OK)
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/libmysqlgcs/src/bindings/xcom/gcs_xcom_control_interface.cc:1767
#5  0x00007fffe0460435 in Gcs_xcom_control::process_control_message (this=0x7fff11a6b020, msg=0x7fff2c098c40, 
    maximum_supported_protocol_version=Gcs_protocol_version::V2, used_protocol_version=Gcs_protocol_version::V2)
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/libmysqlgcs/src/bindings/xcom/gcs_xcom_control_interface.cc:1665
#6  0x00007fffe03ec22f in do_cb_xcom_receive_data_state_exchange (packet=..., xcom_nodes=..., 
    xcom_communication=..., xcom_control=...)
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/libmysqlgcs/src/bindings/xcom/gcs_xcom_interface.cc:1265
#7  0x00007fffe03ec749 in do_cb_xcom_receive_data (
    message_id=..., xcom_nodes_raw_ptr=0x7fff1bde6cc0, 
    cache_last_removed=..., size=529, 
    data_raw_ptr=0x7fff1bdfc3f0 " \300\337\033\377\177")
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/libmysqlgcs/src/bindings/xcom/gcs_xcom---Type <return> to continue, or q <return> to quit---
_interface.cc:1364
#8  0x00007fffe03f82c9 in Data_notification::do_execute (
    this=0x7fff1bd8c510)
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/libmysqlgcs/src/bindings/xcom/gcs_xcom_notification.cc:80
#9  0x00007fffe03fa463 in Parameterized_notification<false>::operator() (this=0x7fff1bd8c510)
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/libmysqlgcs/src/bindings/xcom/gcs_xcom_notification.h:225
#10 0x00007fffe03f8cfa in Gcs_xcom_engine::process (
    this=0x7fff38031b70)
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/libmysqlgcs/src/bindings/xcom/gcs_xcom_notification.cc:219
#11 0x00007fffe03f889f in process_notification_thread (
    ptr_object=0x7fff38031b70)
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/libmysqlgcs/src/bindings/xcom/gcs_xcom_notification.cc:156
#12 0x000055555a809a8c in pfs_spawn_thread (
    arg=0x7fff3812d940)
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/storage/perfschema/pfs.cc:2880
---Type <return> to continue, or q <return> to quit---
#13 0x00007ffff7bbb6db in start_thread (
    arg=0x7fff60ff9700) at pthread_create.c:463
#14 0x00007ffff613871f in clone ()
    at ../sysdeps/unix/sysv/linux/x86_64/clone.S:95

2       breakpoint     keep y   <MULTIPLE>         
2.1                         y     0x00007fffe02b5790 <Gcs_xcom_state_exchange::broadcast_state(Gcs_xcom_view_identifier const&, std::vector<std::unique_ptr<Gcs_message_data, std::default_delete<Gcs_message_data> >, std::allocator<std::unique_ptr<Gcs_message_data, std::default_delete<Gcs_message_data> > > >&)@plt>
2.2                         y     0x00007fffe048645b in Gcs_xcom_state_exchange::broadcast_state(Gcs_xcom_view_identifier const&, std::vector<std::unique_ptr<Gcs_message_data, std::default_delete<Gcs_message_data> >, std::allocator<std::unique_ptr<Gcs_message_data, std::default_delete<Gcs_message_data> > > >&) 
                                                   at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/libmysqlgcs/src/bindings/xcom/gcs_xcom_state_exchange.cc:514



### Group_member_info_manager::update_gtid_sets

Thread 88 "mysqld" hit Breakpoint 2, Group_member_info_manager::update_gtid_sets (this=0x7fff38127c20, 
    uuid="74ff0bf0-3627-11eb-a7bf-70b5e831c9f8", 
    gtid_executed="aaaaaaaa-aaaa-aaaa-aaaa-", 'a' <repeats 12 times>, ":1-56", purged_gtids="", 
    gtid_retrieved="aaaaaaaa-aaaa-aaaa-aaaa-", 'a' <repeats 12 times>, ":1-56")
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/src/member_info.cc:1050
1050                                                     string &gtid_retrieved) {
(gdb) bt
#0  Group_member_info_manager::update_gtid_sets (
    this=0x7fff38127c20, 
    uuid="74ff0bf0-3627-11eb-a7bf-70b5e831c9f8", 
    gtid_executed="aaaaaaaa-aaaa-aaaa-aaaa-", 'a' <repeats 12 times>, ":1-56", purged_gtids="", 
    gtid_retrieved="aaaaaaaa-aaaa-aaaa-aaaa-", 'a' <repeats 12 times>, ":1-56")
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/src/member_info.cc:1050
#1  0x00007fffe03118db in Plugin_gcs_events_handler::get_exchangeable_data (this=0x7fff28017db0)
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/src/gcs_event_handlers.cc:1220
#2  0x00007fffe045f8fd in Gcs_xcom_control::xcom_receive_global_view (this=0x7fff0c0169e0, config_id=..., 
    message_id=..., xcom_nodes=0x7fff01a7a7b0, 
    same_view=false, max_synode=...)
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/libmysqlgcs/src/bindings/xcom/gcs_xcom_control_interface.cc:1533
#3  0x00007fffe03ed1be in do_cb_xcom_receive_global_view (
    config_id=..., message_id=..., 
    xcom_nodes=0x7fff01a7a7b0, event_horizon=10, 
    max_synode=...)
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin---Type <return> to continue, or q <return> to quit---
/group_replication/libmysqlgcs/src/bindings/xcom/gcs_xcom_interface.cc:1519
#4  0x00007fffe03f84f1 in Global_view_notification::do_execute (this=0x7fff019f2660)
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/libmysqlgcs/src/bindings/xcom/gcs_xcom_notification.cc:106
#5  0x00007fffe03fa463 in Parameterized_notification<false>::operator() (this=0x7fff019f2660)
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/libmysqlgcs/src/bindings/xcom/gcs_xcom_notification.h:225
#6  0x00007fffe03f8cfa in Gcs_xcom_engine::process (
    this=0x7fff2c0051b0)
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/libmysqlgcs/src/bindings/xcom/gcs_xcom_notification.cc:219
#7  0x00007fffe03f889f in process_notification_thread (
    ptr_object=0x7fff2c0051b0)
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/plugin/group_replication/libmysqlgcs/src/bindings/xcom/gcs_xcom_notification.cc:156
#8  0x000055555a809a8c in pfs_spawn_thread (
    arg=0x7fff38126e80)
    at /home/zhaoguodong/msBuild/mysql-source-8.0.22/storag---Type <return> to continue, or q <return> to quit---
e/perfschema/pfs.cc:2880
#9  0x00007ffff7bbb6db in start_thread (
    arg=0x7fff60ff9700) at pthread_create.c:463
#10 0x00007ffff613871f in clone ()
    at ../sysdeps/unix/sysv/linux/x86_64/clone.S:95

### Group_member_info_manager::update_member_weight




### select Global gtid_executed_set bt
Thread 40 "mysqld" hit Breakpoint 1, Gtid_set::to_string (this=0x55555facb260, 
    buf=0x7fff4c0ca400 "aaaaaaaa-aaaa-aaaa-aaaa-", 'a' <repeats 12 times>, ":1-163,\naaaaaaaa-aaaa-aaaa-aaaa-", 'a' <repeats 11 times>, "b:1-4", need_lock=false, sf=0x0)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/rpl_gtid_set.cc:761
761                                const Gtid_set::String_format *sf) const {
(gdb) bt
#0  Gtid_set::to_string (this=0x55555facb260, 
    buf=0x7fff4c0ca400 "aaaaaaaa-aaaa-aaaa-aaaa-", 'a' <repeats 12 times>, ":1-163,\naaaaaaaa-aaaa-aaaa-aaaa-", 'a' <repeats 11 times>, "b:1-4", need_lock=false, sf=0x0)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/rpl_gtid_set.cc:761
#1  0x00005555589cd8f0 in Sys_var_gtid_executed::global_value_ptr (
    this=0x55555d638240 <Sys_gtid_executed>, 
    thd=0x7fff4c001000)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/sys_vars.h:2338
#2  0x00005555587594a5 in sys_var::value_ptr (
    this=0x55555d638240 <Sys_gtid_executed>, 
    running_thd=0x7fff4c001000, 
    target_thd=0x7fff4c001000, 
    type=OPT_GLOBAL, base=0x7fff4c0c9998)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/set_var.cc:373
#3  0x000055555875954b in sys_var::value_ptr (
    this=0x55555d638240 <Sys_gtid_executed>, 
    thd=0x7fff4c001000, type=OPT_GLOBAL, 
---Type <return> to continue, or q <return> to quit---
    base=0x7fff4c0c9998)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/set_var.cc:380
#4  0x0000555558d0ef6a in Item_func_get_system_var::val_str (this=0x7fff4c0c98a8, 
    str=0x7fff4c0c99b8)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/item_func.cc:7126
#5  0x0000555558c6f442 in Item::send (
    this=0x7fff4c0c98a8, 
    protocol=0x7fff4c0050f0, 
    buffer=0x7fffe3f281d0)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/item.cc:7065
#6  0x00005555587bab4e in THD::send_result_set_row (this=0x7fff4c001000, row_items=...)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/sql_class.cc:2531
#7  0x0000555558ec8969 in Query_result_send::send_data (this=0x7fff4c0c9e78, 
    thd=0x7fff4c001000, items=...)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/query_result.cc:99
---Type <return> to continue, or q <return> to quit---
#8  0x00005555589907e0 in SELECT_LEX_UNIT::ExecuteIteratorQuery (this=0x7fff4c0c86e8, 
    thd=0x7fff4c001000)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/sql_union.cc:1247
#9  0x0000555558990a46 in SELECT_LEX_UNIT::execute (this=0x7fff4c0c86e8, thd=0x7fff4c001000)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/sql_union.cc:1285
#10 0x00005555588dddce in Sql_cmd_dml::execute_inner (this=0x7fff4c0c9e40, 
    thd=0x7fff4c001000)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/sql_select.cc:940
#11 0x00005555588dd2a6 in Sql_cmd_dml::execute
    (this=0x7fff4c0c9e40, thd=0x7fff4c001000)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/sql_select.cc:725
#12 0x000055555885f310 in mysql_execute_command (thd=0x7fff4c001000, first_level=true)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/sql_parse.cc:4344
#13 0x0000555558861462 in mysql_parse (
---Type <return> to continue, or q <return> to quit---
    thd=0x7fff4c001000, 
    parser_state=0x7fffe3f29cd0)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/sql_parse.cc:4965
#14 0x00005555588574cd in dispatch_command (
    thd=0x7fff4c001000, 
    com_data=0x7fffe3f2acc0, 
    command=COM_QUERY)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/sql_parse.cc:1784
#15 0x0000555558855a1e in do_command (
    thd=0x7fff4c001000)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/sql_parse.cc:1309
#16 0x0000555558a431b7 in handle_connection (
    arg=0x7fff500045e0)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/conn_handler/connection_handler_per_thread.cc:301
#17 0x000055555a809a7c in pfs_spawn_thread (
    arg=0x55555fe03920)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/storage/perfschema/pfs.cc:2880
---Type <return> to continue, or q <return> to quit---
#18 0x00007ffff7bbb6db in start_thread (
    arg=0x7fffe3f2b700)
    at pthread_create.c:463
#19 0x00007ffff613871f in clone ()
    at ../sysdeps/unix/sysv/linux/x86_64/clone


#### 
Thread 45 "mysqld" hit Breakpoint 1, 0x00007fff8ca3d360 in Gtid_set::to_string(char**, bool, Gtid_set::String_format const*) const@plt ()
   from /usr/local/mysql/lib/plugin/group_replication.so
(gdb) bt
#0  0x00007fff8ca3d360 in Gtid_set::to_string(char**, bool, Gtid_set::String_format const*) const@plt ()
   from /usr/local/mysql/lib/plugin/group_replication.so
#1  0x00007fff8ca651cc in Certifier::get_group_stable_transactions_set_string (
    this=0x7fff4c2ef7d0, 
    buffer=0x7fffe3e528a8, 
    length=0x7fffe3e528e0)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/plugin/group_replication/src/certifier.cc:1076
#2  0x00007fff8caec3cd in Pipeline_stats_member_collector::send_stats_member_message (
    this=0x7fff4c2ef3b0, mode=FCM_QUOTA)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/plugin/group_replication/src/pipeline_stats.cc:488
#3  0x00007fff8caed415 in Flow_control_module::flow_control_step (this=0x7fff4c2ef448, 
    member=0x7fff4c2ef3b0)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/plugin/group_replication/src/pipeline_stats.cc:7---Type <return> to continue, or q <return> to quit---
49
#4  0x00007fff8ca58c26 in Applier_module::run_flow_control_step (this=0x7fff4c2ef240)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/plugin/group_replication/include/applier.h:703
#5  0x00007fff8ca60ad6 in Certifier_broadcast_thread::dispatcher (this=0x7fff4c027f20)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/plugin/group_replication/src/certifier.cc:150
#6  0x00007fff8ca60309 in launch_broadcast_thread (arg=0x7fff4c027f20)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/plugin/group_replication/src/certifier.cc:42
#7  0x000055555a809a7c in pfs_spawn_thread (
    arg=0x7fff4c2f0500)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/storage/perfschema/pfs.cc:2880
#8  0x00007ffff7bbb6db in start_thread (
    arg=0x7fffe3e53700)
    at pthread_create.c:463
#9  0x00007ffff613871f in clone ()
    at ../sysdeps/unix/sysv/linux/x86_64/clone.


#### 更新权重bt

Thread 41 "mysqld" hit Breakpoint 1, update_member_weight (
    var_ptr=0x7fff6bf7dc48 <ov+744>, 
    save=0x7fff740c99a8)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/plugin/group_replication/src/plugin.cc:3374
3374                                     const void *save) {
#0  update_member_weight (
    var_ptr=0x7fff6bf7dc48 <ov+744>, 
    save=0x7fff740c99a8)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/plugin/group_replication/src/plugin.cc:3374
#1  0x000055555889bb29 in sys_var_pluginvar::global_update (this=0x55555fb79948, thd=
    0x7fff740008d0, var=0x7fff740c9988)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/sql_plugin_var.cc:427
#2  0x0000555558758e97 in sys_var::update (
    this=0x55555fb79948, 
    thd=0x7fff740008d0, var=0x7fff740c9988)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/set_var.cc:297
#3  0x000055555875bc1d in set_var::update (
    this=0x7fff740c9988, 
    thd=0x7fff740008d0)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/set_var.cc:1121
#4  0x000055555875ac3d in sql_set_variables

    (thd=0x7fff740008d0, 
---Type <return> to continue, or q <return> to quit---
    var_list=0x7fff74003b60, opened=true)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/set_var.cc:801
#5  0x000055555885c29e in mysql_execute_command (thd=0x7fff740008d0, first_level=true)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/sql_parse.cc:3403
#6  0x0000555558861462 in mysql_parse (
    thd=0x7fff740008d0, 
    parser_state=0x7fffe3f29cd0)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/sql_parse.cc:4965
#7  0x00005555588574cd in dispatch_command
    (thd=0x7fff740008d0, 
    com_data=0x7fffe3f2acc0, 
    command=COM_QUERY)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/sql_parse.cc:1784
#8  0x0000555558855a1e in do_command (
    thd=0x7fff740008d0)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/sql_parse.cc:1309
#9  0x0000555558a431b7 in handle_connection
---Type <return> to continue, or q <return> to quit---
    (arg=0x7fff4c0045e0)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/conn_handler/connection_handler_per_thread.cc:301
#10 0x000055555a809a7c in pfs_spawn_thread
    (arg=0x55555fbad5a0)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/storage/perfschema/pfs.cc:2880
#11 0x00007ffff7bbb6db in start_thread (
    arg=0x7fffe3f2b700)
    at pthread_create.c:463
#12 0x00007ffff613871f in clone ()
    at ../sysdeps/unix/sysv/linux/x86_64/clone.S:95



Thread 41 "mysqld" hit Breakpoint 2, check_group_name (thd=0x7fff44001000, 
    save=0x7fff4411ad70, 
    value=0x7fffe3f28470)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/plugin/group_replication/src/plugin.cc:2461
2461                                struct st_mysql_value *value) {
(gdb) bt
#0  check_group_name (thd=0x7fff44001000, 
    save=0x7fff4411ad70, 
    value=0x7fffe3f28470)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/plugin/group_replication/src/plugin.cc:2461
#1  0x000055555889b5eb in sys_var_pluginvar::do_check (this=0x55555fb6e4f0, 
    thd=0x7fff44001000, var=0x7fff4411ad50)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/sql_plugin_var.cc:332
#2  0x0000555558759203 in sys_var::check (
    this=0x55555fb6e4f0, 
    thd=0x7fff44001000, var=0x7fff4411ad50)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/set_var.cc:347
#3  0x000055555875b776 in set_var::check (
    this=0x7fff4411ad50, 
    thd=0x7fff44001000)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/set_var.cc:1030
#4  0x000055555875ab99 in sql_set_variables
    (thd=0x7fff44001000, 
---Type <return> to continue, or q <return> to quit---
    var_list=0x7fff44004300, opened=true)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/set_var.cc:795
#5  0x000055555885c29e in mysql_execute_command (thd=0x7fff44001000, first_level=true)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/sql_parse.cc:3403
#6  0x0000555558861462 in mysql_parse (
    thd=0x7fff44001000, 
    parser_state=0x7fffe3f29cd0)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/sql_parse.cc:4965
#7  0x00005555588574cd in dispatch_command
    (thd=0x7fff44001000, 
    com_data=0x7fffe3f2acc0, 
    command=COM_QUERY)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/sql_parse.cc:1784
#8  0x0000555558855a1e in do_command (
    thd=0x7fff44001000)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/sql_parse.cc:1309
#9  0x0000555558a431b7 in handle_connection
---Type <return> to continue, or q <return> to quit---
    (arg=0x7fff580045e0)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/conn_handler/connection_handler_per_thread.cc:301
#10 0x000055555a809a7c in pfs_spawn_thread
    (arg=0x55555fb12ff0)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/storage/perfschema/pfs.cc:2880
#11 0x00007ffff7bbb6db in start_thread (
    arg=0x7fffe3f2b700)
    at pthread_create.c:463
#12 0x00007ffff613871f in clone ()
    at ../sysdeps/unix/sysv/linux/x86_64/clone.S:95



#### replication_group_name

Thread 41 "mysqld" hit Hardware watchpoint 3: ov.group_name_var

Old value = 0x55555fb8b370 "aaaaaaaa-aaaa-aaaa-aaaa-", 'a' <repeats 12 times>
New value = 0x7fff159b4790 "aaaaaaaa-aaaa-aaaa-aaaa-", 'a' <repeats 11 times>, "b"
update_func_str (
    tgt=0x7fff6bf7d9b8 <ov+88>, 
    save=0x7fffe3f286b0)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/sql_plugin_var.cc:786
786     }
(gdb) bt
#0  update_func_str (
    tgt=0x7fff6bf7d9b8 <ov+88>, 
    save=0x7fffe3f286b0)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/sql_plugin_var.cc:786
#1  0x000055555889ac28 in plugin_var_memalloc_global_update (thd=0x7fff44001000, 
    var=0x7fff6bf7a9a0 <mysql_sysvar_group_name>, dest=0x7fff6bf7d9b8 <ov+88>, 
    value=0x7fff159b4790 "aaaaaaaa-aaaa-aaaa-aaaa-", 'a' <repeats 11 times>, "b")
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/sql_plugin_var.cc:75
#2  0x000055555889bafc in sys_var_pluginvar::global_update (this=0x55555fb6e4f0, 
    thd=0x7fff44001000, var=0x7fff4411ad50)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/sql_plugin_var.cc:423
#3  0x0000555558758e97 in sys_var::update (
    this=0x55555fb6e4f0, 
    thd=0x7fff44001000, var=0x7fff4411ad50)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/set_var.cc:297
---Type <return> to continue, or q <return> to quit---
#4  0x000055555875bc1d in set_var::update (
    this=0x7fff4411ad50, 
    thd=0x7fff44001000)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/set_var.cc:1121
#5  0x000055555875ac3d in sql_set_variables
    (thd=0x7fff44001000, 
    var_list=0x7fff44004300, opened=true)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/set_var.cc:801
#6  0x000055555885c29e in mysql_execute_command (thd=0x7fff44001000, first_level=true)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/sql_parse.cc:3403
#7  0x0000555558861462 in mysql_parse (
    thd=0x7fff44001000, 
    parser_state=0x7fffe3f29cd0)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/sql_parse.cc:4965
#8  0x00005555588574cd in dispatch_command
    (thd=0x7fff44001000, 
    com_data=0x7fffe3f2acc0, 
    command=COM_QUERY)
---Type <return> to continue, or q <return> to quit---
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/sql_parse.cc:1784
#9  0x0000555558855a1e in do_command (
    thd=0x7fff44001000)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/sql_parse.cc:1309
#10 0x0000555558a431b7 in handle_connection
    (arg=0x7fff580045e0)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/conn_handler/connection_handler_per_thread.cc:301
#11 0x000055555a809a7c in pfs_spawn_thread
    (arg=0x55555fb12ff0)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/storage/perfschema/pfs.cc:2880
#12 0x00007ffff7bbb6db in start_thread (
    arg=0x7fffe3f2b700)
    at pthread_create.c:463
#13 0x00007ffff613871f in clone ()
    at ../sysdeps/unix/sysv/linux/x86_64/clone.S:95

??????????????????????? 修改一个节点的权重时，无论在重新选主前还是后都没有捕获到这个断点？？？？？？？？？？？

#### ov.group_name_var bt

Thread 41 "mysqld" hit Hardware watchpoint 3: ov.group_name_var

Old value = 0x7fff742f11d0 "aaaaaaaa-aaaa-aaaa-aaaa-", 'a' <repeats 12 times>
New value = 0x7fff740d6930 "aaaaaaaa-aaaa-aaaa-aaaa-", 'a' <repeats 11 times>, "b"
update_func_str (
    tgt=0x7fff6bf7d9b8 <ov+88>, 
    save=0x7fffe3f286b0)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/sql_plugin_var.cc:786
786     }
(gdb) bt
#0  update_func_str (
    tgt=0x7fff6bf7d9b8 <ov+88>, 
    save=0x7fffe3f286b0)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/sql_plugin_var.cc:786
#1  0x000055555889ac28 in plugin_var_memalloc_global_update (thd=0x7fff740008d0, 
    var=0x7fff6bf7a9a0 <mysql_sysvar_group_name>, dest=0x7fff6bf7d9b8 <ov+88>, 
    value=0x7fff740d6930 "aaaaaaaa-aaaa-aaaa-aaaa-", 'a' <repeats 11 times>, "b")
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/sql_plugin_var.cc:75
#2  0x000055555889bafc in sys_var_pluginvar::global_update (this=0x55555fb6e4f0, 
    thd=0x7fff740008d0, var=0x7fff7430a330)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/sql_plugin_var.cc:423
#3  0x0000555558758e97 in sys_var::update (
    this=0x55555fb6e4f0, 
    thd=0x7fff740008d0, var=0x7fff7430a330)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/set_var.cc:297
---Type <return> to continue, or q <return> to quit---
#4  0x000055555875bc1d in set_var::update (
    this=0x7fff7430a330, 
    thd=0x7fff740008d0)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/set_var.cc:1121
#5  0x000055555875ac3d in sql_set_variables
    (thd=0x7fff740008d0, 
    var_list=0x7fff74006730, opened=true)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/set_var.cc:801
#6  0x000055555885c29e in mysql_execute_command (thd=0x7fff740008d0, first_level=true)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/sql_parse.cc:3403
#7  0x0000555558861462 in mysql_parse (
    thd=0x7fff740008d0, 
    parser_state=0x7fffe3f29cd0)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/sql_parse.cc:4965
#8  0x00005555588574cd in dispatch_command
    (thd=0x7fff740008d0, 
    com_data=0x7fffe3f2acc0, 
    command=COM_QUERY)
---Type <return> to continue, or q <return> to quit---
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/sql_parse.cc:1784
#9  0x0000555558855a1e in do_command (
    thd=0x7fff740008d0)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/sql_parse.cc:1309
#10 0x0000555558a431b7 in handle_connection
    (arg=0x7fff4c0045e0)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/sql/conn_handler/connection_handler_per_thread.cc:301
#11 0x000055555a809a7c in pfs_spawn_thread
    (arg=0x55555fbad5a0)
    at /home/zhaoguodong/msBuild/mysql-8.0.22/storage/perfschema/pfs.cc:2880
#12 0x00007ffff7bbb6db in start_thread (
    arg=0x7fffe3f2b700)
    at pthread_create.c:463
#13 0x00007ffff613871f in clone ()
    at ../sysdeps/unix/sysv/linux/x86_64/clone.S:95


+---------------------------+---------------------+--------------------------------------+-----------------------------+----------------------------+--------------------------+------------------------------------+-------------------------------------------+--------------------------------+--------------------------------------------+-----------------------------------+-----------------------------------+-----------------------------------+
| CHANNEL_NAME              | VIEW_ID             | MEMBER_ID                            | COUNT_TRANSACTIONS_IN_QUEUE | COUNT_TRANSACTIONS_CHECKED | COUNT_CONFLICTS_DETECTED | COUNT_TRANSACTIONS_ROWS_VALIDATING | TRANSACTIONS_COMMITTED_ALL_MEMBERS        | LAST_CONFLICT_FREE_TRANSACTION | COUNT_TRANSACTIONS_REMOTE_IN_APPLIER_QUEUE | COUNT_TRANSACTIONS_REMOTE_APPLIED | COUNT_TRANSACTIONS_LOCAL_PROPOSED | COUNT_TRANSACTIONS_LOCAL_ROLLBACK |
+---------------------------+---------------------+--------------------------------------+-----------------------------+----------------------------+--------------------------+------------------------------------+-------------------------------------------+--------------------------------+--------------------------------------------+-----------------------------------+-----------------------------------+-----------------------------------+
| group_replication_applier | 16074807280060683:2 | 69511060-3627-11eb-9fad-70b5e831c9f8 |                           0 |                          0 |                        0 |                                  0 | aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-61 |                                |                                          0 |                                 1 |                                 0 |                                 0 |
| group_replication_applier | 16074807280060683:2 | 6f2ca203-3627-11eb-8cd9-70b5e831c9f8 |                           0 |                          0 |                        0 |                                  0 |                                           |                                |                                          0 |                                 0 |                                 0 |                                 0 |
+---------------------------+---------------------+--------------------------------------+-----------------------------+----------------------------+--------------------------+------------------------------------+-------------------------------------------+--------------------------------+--------------------------------------------+-----------------------------------+-----------------------------------+-----------------------------------+

+---------------------------+---------------------+--------------------------------------+-----------------------------+----------------------------+--------------------------+------------------------------------+-------------------------------------------+--------------------------------+--------------------------------------------+-----------------------------------+-----------------------------------+-----------------------------------+
| CHANNEL_NAME              | VIEW_ID             | MEMBER_ID                            | COUNT_TRANSACTIONS_IN_QUEUE | COUNT_TRANSACTIONS_CHECKED | COUNT_CONFLICTS_DETECTED | COUNT_TRANSACTIONS_ROWS_VALIDATING | TRANSACTIONS_COMMITTED_ALL_MEMBERS        | LAST_CONFLICT_FREE_TRANSACTION | COUNT_TRANSACTIONS_REMOTE_IN_APPLIER_QUEUE | COUNT_TRANSACTIONS_REMOTE_APPLIED | COUNT_TRANSACTIONS_LOCAL_PROPOSED | COUNT_TRANSACTIONS_LOCAL_ROLLBACK |
+---------------------------+---------------------+--------------------------------------+-----------------------------+----------------------------+--------------------------+------------------------------------+-------------------------------------------+--------------------------------+--------------------------------------------+-----------------------------------+-----------------------------------+-----------------------------------+
| group_replication_applier | 16074807280060683:3 | 69511060-3627-11eb-9fad-70b5e831c9f8 |                           0 |                          0 |                        0 |                                  0 | aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-62 |                                |                                          0 |                                 2 |                                 0 |                                 0 |
| group_replication_applier | 16074807280060683:3 | 6f2ca203-3627-11eb-8cd9-70b5e831c9f8 |                           0 |                          0 |                        0 |                                  0 | aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-62 |                                |                                          0 |                                 1 |                                 0 |                                 0 |
| group_replication_applier | 16074807280060683:3 | 74ff0bf0-3627-11eb-a7bf-70b5e831c9f8 |                           0 |                          0 |                        0 |                                  0 |                                           |                                |                                          0 |                                 0 |                                 0 |                                 0 |
+---------------------------+---------------------+--------------------------------------+-----------------------------+----------------------------+--------------------------+------------------------------------+-------------------------------------------+--------------------------------+--------------------------------------------+-----------------------------------+-----------------------------------+-----------------------------------+

+---------------------------+---------------------+--------------------------------------+-----------------------------+----------------------------+--------------------------+------------------------------------+-------------------------------------------+--------------------------------+--------------------------------------------+-----------------------------------+-----------------------------------+-----------------------------------+
| CHANNEL_NAME              | VIEW_ID             | MEMBER_ID                            | COUNT_TRANSACTIONS_IN_QUEUE | COUNT_TRANSACTIONS_CHECKED | COUNT_CONFLICTS_DETECTED | COUNT_TRANSACTIONS_ROWS_VALIDATING | TRANSACTIONS_COMMITTED_ALL_MEMBERS        | LAST_CONFLICT_FREE_TRANSACTION | COUNT_TRANSACTIONS_REMOTE_IN_APPLIER_QUEUE | COUNT_TRANSACTIONS_REMOTE_APPLIED | COUNT_TRANSACTIONS_LOCAL_PROPOSED | COUNT_TRANSACTIONS_LOCAL_ROLLBACK |
+---------------------------+---------------------+--------------------------------------+-----------------------------+----------------------------+--------------------------+------------------------------------+-------------------------------------------+--------------------------------+--------------------------------------------+-----------------------------------+-----------------------------------+-----------------------------------+
| group_replication_applier | 16074807280060683:3 | 69511060-3627-11eb-9fad-70b5e831c9f8 |                           0 |                          0 |                        0 |                                  0 | aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-62 |                                |                                          0 |                                 2 |                                 0 |                                 0 |
| group_replication_applier | 16074807280060683:3 | 6f2ca203-3627-11eb-8cd9-70b5e831c9f8 |                           0 |                          0 |                        0 |                                  0 | aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-62 |                                |                                          0 |                                 1 |                                 0 |                                 0 |
| group_replication_applier | 16074807280060683:3 | 74ff0bf0-3627-11eb-a7bf-70b5e831c9f8 |                           0 |                          0 |                        0 |                                  0 |                                           |                                |                                          0 |                                 0 |                                 0 |                                 0 |
+---------------------------+---------------------+--------------------------------------+-----------------------------+----------------------------+--------------------------+------------------------------------+-------------------------------------------+--------------------------------+--------------------------------------------+-----------------------------------+-----------------------------------+-----------------------------------+

+---------------------------+---------------------+--------------------------------------+-----------------------------+----------------------------+--------------------------+------------------------------------+-------------------------------------------+--------------------------------+--------------------------------------------+-----------------------------------+-----------------------------------+-----------------------------------+
| CHANNEL_NAME              | VIEW_ID             | MEMBER_ID                            | COUNT_TRANSACTIONS_IN_QUEUE | COUNT_TRANSACTIONS_CHECKED | COUNT_CONFLICTS_DETECTED | COUNT_TRANSACTIONS_ROWS_VALIDATING | TRANSACTIONS_COMMITTED_ALL_MEMBERS        | LAST_CONFLICT_FREE_TRANSACTION | COUNT_TRANSACTIONS_REMOTE_IN_APPLIER_QUEUE | COUNT_TRANSACTIONS_REMOTE_APPLIED | COUNT_TRANSACTIONS_LOCAL_PROPOSED | COUNT_TRANSACTIONS_LOCAL_ROLLBACK |
+---------------------------+---------------------+--------------------------------------+-----------------------------+----------------------------+--------------------------+------------------------------------+-------------------------------------------+--------------------------------+--------------------------------------------+-----------------------------------+-----------------------------------+-----------------------------------+
| group_replication_applier | 16074807280060683:3 | 69511060-3627-11eb-9fad-70b5e831c9f8 |                           0 |                          0 |                        0 |                                  0 | aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-62 |                                |                                          0 |                                 2 |                                 0 |                                 0 |
| group_replication_applier | 16074807280060683:3 | 6f2ca203-3627-11eb-8cd9-70b5e831c9f8 |                           0 |                          0 |                        0 |                                  0 | aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-62 |                                |                                          0 |                                 1 |                                 0 |                                 0 |
| group_replication_applier | 16074807280060683:3 | 74ff0bf0-3627-11eb-a7bf-70b5e831c9f8 |                           0 |                          0 |                        0 |                                  0 |                                           |                                |                                          0 |                                 0 |                                 0 |                                 0 |
+---------------------------+---------------------+--------------------------------------+-----------------------------+----------------------------+--------------------------+------------------------------------+-------------------------------------------+--------------------------------+--------------------------------------------+-----------------------------------+-----------------------------------+-----------------------------------+

+---------------------------+---------------------+--------------------------------------+-----------------------------+----------------------------+--------------------------+------------------------------------+-------------------------------------------+--------------------------------+--------------------------------------------+-----------------------------------+-----------------------------------+-----------------------------------+
| CHANNEL_NAME              | VIEW_ID             | MEMBER_ID                            | COUNT_TRANSACTIONS_IN_QUEUE | COUNT_TRANSACTIONS_CHECKED | COUNT_CONFLICTS_DETECTED | COUNT_TRANSACTIONS_ROWS_VALIDATING | TRANSACTIONS_COMMITTED_ALL_MEMBERS        | LAST_CONFLICT_FREE_TRANSACTION | COUNT_TRANSACTIONS_REMOTE_IN_APPLIER_QUEUE | COUNT_TRANSACTIONS_REMOTE_APPLIED | COUNT_TRANSACTIONS_LOCAL_PROPOSED | COUNT_TRANSACTIONS_LOCAL_ROLLBACK |
+---------------------------+---------------------+--------------------------------------+-----------------------------+----------------------------+--------------------------+------------------------------------+-------------------------------------------+--------------------------------+--------------------------------------------+-----------------------------------+-----------------------------------+-----------------------------------+
| group_replication_applier | 16074807280060683:5 | 69511060-3627-11eb-9fad-70b5e831c9f8 |                           0 |                          0 |                        0 |                                  0 | aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-63 |                                |                                          0 |                                 3 |                                 0 |                                 0 |
| group_replication_applier | 16074807280060683:5 | 6f2ca203-3627-11eb-8cd9-70b5e831c9f8 |                           0 |                          0 |                        0 |                                  0 |                                           |                                |                                          0 |                                 1 |                                 0 |                                 0 |
| group_replication_applier | 16074807280060683:5 | 74ff0bf0-3627-11eb-a7bf-70b5e831c9f8 |                           0 |                          0 |                        0 |                                  0 | aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-63 |                                |                                          0 |                                 1 |                                 0 |                                 0 |
+---------------------------+---------------------+--------------------------------------+-----------------------------+----------------------------+--------------------------+------------------------------------+-------------------------------------------+--------------------------------+--------------------------------------------+-----------------------------------+-----------------------------------+-----------------------------------+


+---------------------------+---------------------+--------------------------------------+-----------------------------+----------------------------+--------------------------+------------------------------------+-------------------------------------------+--------------------------------+--------------------------------------------+-----------------------------------+-----------------------------------+-----------------------------------+
| CHANNEL_NAME              | VIEW_ID             | MEMBER_ID                            | COUNT_TRANSACTIONS_IN_QUEUE | COUNT_TRANSACTIONS_CHECKED | COUNT_CONFLICTS_DETECTED | COUNT_TRANSACTIONS_ROWS_VALIDATING | TRANSACTIONS_COMMITTED_ALL_MEMBERS        | LAST_CONFLICT_FREE_TRANSACTION | COUNT_TRANSACTIONS_REMOTE_IN_APPLIER_QUEUE | COUNT_TRANSACTIONS_REMOTE_APPLIED | COUNT_TRANSACTIONS_LOCAL_PROPOSED | COUNT_TRANSACTIONS_LOCAL_ROLLBACK |
+---------------------------+---------------------+--------------------------------------+-----------------------------+----------------------------+--------------------------+------------------------------------+-------------------------------------------+--------------------------------+--------------------------------------------+-----------------------------------+-----------------------------------+-----------------------------------+
| group_replication_applier | 16074818349510409:2 | 69511060-3627-11eb-9fad-70b5e831c9f8 |                           0 |                          0 |                        0 |                                  0 | aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-65 |                                |                                          0 |                                 1 |                                 0 |                                 0 |
| group_replication_applier | 16074818349510409:2 | 6f2ca203-3627-11eb-8cd9-70b5e831c9f8 |                           0 |                          0 |                        0 |                                  0 |                                           |                                |                                          0 |                                 1 |                                 0 |                                 0 |
+---------------------------+---------------------+--------------------------------------+-----------------------------+----------------------------+--------------------------+------------------------------------+-------------------------------------------+--------------------------------+--------------------------------------------+-----------------------------------+-----------------------------------+-----------------------------------+


+---------------------------+---------------------+--------------------------------------+-----------------------------+----------------------------+--------------------------+------------------------------------+-------------------------------------------+-----------------------------------------+--------------------------------------------+-----------------------------------+-----------------------------------+-----------------------------------+
| CHANNEL_NAME              | VIEW_ID             | MEMBER_ID                            | COUNT_TRANSACTIONS_IN_QUEUE | COUNT_TRANSACTIONS_CHECKED | COUNT_CONFLICTS_DETECTED | COUNT_TRANSACTIONS_ROWS_VALIDATING | TRANSACTIONS_COMMITTED_ALL_MEMBERS        | LAST_CONFLICT_FREE_TRANSACTION          | COUNT_TRANSACTIONS_REMOTE_IN_APPLIER_QUEUE | COUNT_TRANSACTIONS_REMOTE_APPLIED | COUNT_TRANSACTIONS_LOCAL_PROPOSED | COUNT_TRANSACTIONS_LOCAL_ROLLBACK |
+---------------------------+---------------------+--------------------------------------+-----------------------------+----------------------------+--------------------------+------------------------------------+-------------------------------------------+-----------------------------------------+--------------------------------------------+-----------------------------------+-----------------------------------+-----------------------------------+
| group_replication_applier | 16074933089340898:3 | 69511060-3627-11eb-9fad-70b5e831c9f8 |                           0 |                         20 |                        0 |                             100000 | aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-73 | aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:93 |                                          0 |                                 2 |                                21 |                                 0 |
| group_replication_applier | 16074933089340898:3 | 6f2ca203-3627-11eb-8cd9-70b5e831c9f8 |                           0 |                         20 |                        0 |                             100000 | aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-73 | aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:93 |                                          0 |                                21 |                                 0 |                                 0 |
| group_replication_applier | 16074933089340898:3 | 74ff0bf0-3627-11eb-a7bf-70b5e831c9f8 |                           0 |                         20 |                        0 |                             100000 | aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-73 | aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:93 |                                          0 |                                20 |                                 0 |                                 0 |
+---------------------------+---------------------+--------------------------------------+-----------------------------+----------------------------+--------------------------+------------------------------------+-------------------------------------------+-----------------------------------------+--------------------------------------------+-----------------------------------+-----------------------------------+-----------------------------------+

+---------------------------+---------------------+--------------------------------------+-----------------------------+----------------------------+--------------------------+------------------------------------+-------------------------------------------+-----------------------------------------+--------------------------------------------+-----------------------------------+-----------------------------------+-----------------------------------+
| CHANNEL_NAME              | VIEW_ID             | MEMBER_ID                            | COUNT_TRANSACTIONS_IN_QUEUE | COUNT_TRANSACTIONS_CHECKED | COUNT_CONFLICTS_DETECTED | COUNT_TRANSACTIONS_ROWS_VALIDATING | TRANSACTIONS_COMMITTED_ALL_MEMBERS        | LAST_CONFLICT_FREE_TRANSACTION          | COUNT_TRANSACTIONS_REMOTE_IN_APPLIER_QUEUE | COUNT_TRANSACTIONS_REMOTE_APPLIED | COUNT_TRANSACTIONS_LOCAL_PROPOSED | COUNT_TRANSACTIONS_LOCAL_ROLLBACK |
+---------------------------+---------------------+--------------------------------------+-----------------------------+----------------------------+--------------------------+------------------------------------+-------------------------------------------+-----------------------------------------+--------------------------------------------+-----------------------------------+-----------------------------------+-----------------------------------+
| group_replication_applier | 16074933089340898:3 | 69511060-3627-11eb-9fad-70b5e831c9f8 |                           0 |                         20 |                        0 |                             100000 | aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-73 | aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:93 |                                          0 |                                 2 |                                21 |                                 0 |
| group_replication_applier | 16074933089340898:3 | 6f2ca203-3627-11eb-8cd9-70b5e831c9f8 |                           0 |                         20 |                        0 |                             100000 | aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-73 | aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:93 |                                          0 |                                21 |                                 0 |                                 0 |
| group_replication_applier | 16074933089340898:3 | 74ff0bf0-3627-11eb-a7bf-70b5e831c9f8 |                           0 |                         20 |                        0 |                             100000 | aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-73 | aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:93 |                                          0 |                                20 |                                 0 |                                 0 |
+---------------------------+---------------------+--------------------------------------+-----------------------------+----------------------------+--------------------------+------------------------------------+-------------------------------------------+-----------------------------------------+--------------------------------------------+-----------------------------------+-----------------------------------+-----------------------------------+

+---------------------------+---------------------+--------------------------------------+-----------------------------+----------------------------+--------------------------+------------------------------------+-------------------------------------------+-----------------------------------------+--------------------------------------------+-----------------------------------+-----------------------------------+-----------------------------------+
| CHANNEL_NAME              | VIEW_ID             | MEMBER_ID                            | COUNT_TRANSACTIONS_IN_QUEUE | COUNT_TRANSACTIONS_CHECKED | COUNT_CONFLICTS_DETECTED | COUNT_TRANSACTIONS_ROWS_VALIDATING | TRANSACTIONS_COMMITTED_ALL_MEMBERS        | LAST_CONFLICT_FREE_TRANSACTION          | COUNT_TRANSACTIONS_REMOTE_IN_APPLIER_QUEUE | COUNT_TRANSACTIONS_REMOTE_APPLIED | COUNT_TRANSACTIONS_LOCAL_PROPOSED | COUNT_TRANSACTIONS_LOCAL_ROLLBACK |
+---------------------------+---------------------+--------------------------------------+-----------------------------+----------------------------+--------------------------+------------------------------------+-------------------------------------------+-----------------------------------------+--------------------------------------------+-----------------------------------+-----------------------------------+-----------------------------------+
| group_replication_applier | 16074933089340898:3 | 69511060-3627-11eb-9fad-70b5e831c9f8 |                           0 |                         20 |                        0 |                             100000 | aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-73 | aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:93 |                                          0 |                                 2 |                                21 |                                 0 |
| group_replication_applier | 16074933089340898:3 | 6f2ca203-3627-11eb-8cd9-70b5e831c9f8 |                           0 |                         20 |                        0 |                             100000 | aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-73 | aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:93 |                                          0 |                                21 |                                 0 |                                 0 |
| group_replication_applier | 16074933089340898:3 | 74ff0bf0-3627-11eb-a7bf-70b5e831c9f8 |                           0 |                         20 |                        0 |                             100000 | aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-73 | aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:93 |                                          0 |                                20 |                                 0 |                                 0 |
+---------------------------+---------------------+--------------------------------------+-----------------------------+----------------------------+--------------------------+------------------------------------+-------------------------------------------+-----------------------------------------+--------------------------------------------+-----------------------------------+-----------------------------------+-----------------------------------+

+----+-----------------+-----------------+-----------+---------+-------+--------------------------------------------------------+----------------------------------+
| Id | User            | Host            | db        | Command | Time  | State                                                  | Info                             |
+----+-----------------+-----------------+-----------+---------+-------+--------------------------------------------------------+----------------------------------+
|  5 | event_scheduler | localhost       | NULL      | Daemon  | 77921 | Waiting on empty queue                                 | NULL                             |
| 10 | system user     |                 | NULL      | Connect | 77821 | waiting for handler commit                             | Group replication applier module |
| 13 | system user     |                 | NULL      | Query   | 77821 | Slave has read all relay log; waiting for more updates | NULL                             |
| 27 | root            | localhost:60722 | tpcc_test | Query   |     0 | init                                                   | show processlist                 |
| 28 | root            | localhost:60774 | tpcc_test | Query   |   156 | waiting for handler commit                             | commit                           |
+----+-----------------+-----------------+-----------+---------+-------+--------------------------------------------------------+----------------------------------+

+--------+-----------+---------------------+-----------------------+------------------+------------+---------------------+-----------+---------------------+-------------------+-------------------+------------------+-----------------------+-----------------+-------------------+-------------------------+---------------------+-------------------+------------------------+----------------------------+---------------------------+---------------------------+------------------+----------------------------+---------------------+
| trx_id | trx_state | trx_started         | trx_requested_lock_id | trx_wait_started | trx_weight | trx_mysql_thread_id | trx_query | trx_operation_state | trx_tables_in_use | trx_tables_locked | trx_lock_structs | trx_lock_memory_bytes | trx_rows_locked | trx_rows_modified | trx_concurrency_tickets | trx_isolation_level | trx_unique_checks | trx_foreign_key_checks | trx_last_foreign_key_error | trx_adaptive_hash_latched | trx_adaptive_hash_timeout | trx_is_read_only | trx_autocommit_non_locking | trx_schedule_weight |
+--------+-----------+---------------------+-----------------------+------------------+------------+---------------------+-----------+---------------------+-------------------+-------------------+------------------+-----------------------+-----------------+-------------------+-------------------------+---------------------+-------------------+------------------------+----------------------------+---------------------------+---------------------------+------------------+----------------------------+---------------------+
|   2629 | RUNNING   | 2020-12-11 12:33:51 | NULL                  | NULL             |     100014 |                  65 | commit    | NULL                |                 0 |                 3 |                3 |                  1200 |               0 |            100011 |                       0 | REPEATABLE READ     |                 0 |                      0 | NULL                       |                         0 |                         0 |                0 |                          0 |                NULL |
+--------+-----------+---------------------+-----------------------+------------------+------------+---------------------+-----------+---------------------+-------------------+-------------------+------------------+-----------------------+-----------------+-------------------+-------------------------+---------------------+-------------------+------------------------+----------------------------+---------------------------+---------------------------+------------------+----------------------------+---------------------+


+--------+--------------------------------------+-----------------------+-----------+----------+---------------+-------------+----------------+-------------------+------------+-----------------------+-----------+-----------+-------------+-----------+
| ENGINE | ENGINE_LOCK_ID                       | ENGINE_TRANSACTION_ID | THREAD_ID | EVENT_ID | OBJECT_SCHEMA | OBJECT_NAME | PARTITION_NAME | SUBPARTITION_NAME | INDEX_NAME | OBJECT_INSTANCE_BEGIN | LOCK_TYPE | LOCK_MODE | LOCK_STATUS | LOCK_DATA |
+--------+--------------------------------------+-----------------------+-----------+----------+---------------+-------------+----------------+-------------------+------------+-----------------------+-----------+-----------+-------------+-----------+
| INNODB | 140572434386088:1088:140572333545312 |                  2629 |       103 |   100019 | tpcc_test     | warehouse   | NULL           | NULL              | NULL       |       140572333545312 | TABLE     | IX        | GRANTED     | NULL      |
| INNODB | 140572434386088:1096:140572333545408 |                  2629 |       103 |   100020 | tpcc_test     | stock       | NULL           | NULL              | NULL       |       140572333545408 | TABLE     | IX        | GRANTED     | NULL      |
| INNODB | 140572434386088:1089:140572333545504 |                  2629 |       103 |   200020 | tpcc_test     | district    | NULL           | NULL              | NULL       |       140572333545504 | TABLE     | IX        | GRANTED     | NULL      |
+--------+--------------------------------------+-----------------------+-----------+----------+---------------+-------------+----------------+-------------------+------------+-----------------------+-----------+-----------+-------------+-----------+

#### show processlist;
+----+-----------------+-----------------+-----------+---------+------+--------------------------------------------------------+----------------------------------+
| Id | User            | Host            | db        | Command | Time | State                                                  | Info                             |
+----+-----------------+-----------------+-----------+---------+------+--------------------------------------------------------+----------------------------------+
|  5 | event_scheduler | localhost       | NULL      | Daemon  |  793 | Waiting on empty queue                                 | NULL                             |
|  8 | root            | localhost:38414 | tpcc_test | Query   |    0 | init                                                   | show processlist                 |
| 10 | system user     |                 | NULL      | Connect |  473 | waiting for handler commit                             | Group replication applier module |
| 13 | system user     |                 | NULL      | Query   |  473 | Slave has read all relay log; waiting for more updates | NULL                             |
| 28 | root            | localhost:38726 | tpcc_test | Query   |   32 | waiting for handler commit                             | commit                           |
+----+-----------------+-----------------+-----------+---------+------+--------------------------------------------------------+----------------------------------+


--------------------------------------
uuid: 9cddd7e3-3ec1-11eb-81a5-70b5e831c9f8
role: 1
group_name: 
member_id(): 127.0.0.1:24901
member_weight: 50
gtid_executed: aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-44260,
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaab:1-40601
gtid_purged: 
gtid_retrieved: aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-44260,
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaab:1-40601
++++++++++++++++++++++++++++++++++++
uuid: 9fd890c7-3ec1-11eb-a87b-70b5e831c9f8
role: 2
group_name: aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa
member_id(): 127.0.0.1:24902
member_weight: 50
gtid_executed: aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-44260,
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaab:1-40601
gtid_purged: 
gtid_retrieved: aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-44253:44255-44258:44260,
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaab:2-40601
++++++++++++++++++++++++++++++++++++
uuid: a2dd6444-3ec1-11eb-9576-70b5e831c9f8
role: 2
group_name: 
member_id(): 127.0.0.1:24903
member_weight: 50
gtid_executed: aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-44258,
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaab:1-40601
gtid_purged: 
gtid_retrieved: aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-44253:44256-44258,
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaab:3-40601
++++++++++++++++++++++++++++++++++++
--------------------------------------
//////////////1///////////// 
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-44260,
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaab:1-40601|||
9fd890c7-3ec1-11eb-a87b-70b5e831c9f8---:1-44260---:44260
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-44260,
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaab:1-40601|||
9cddd7e3-3ec1-11eb-81a5-70b5e831c9f8---:1-44260---:44260
/////////////2////////////// 
//////////////1///////////// 
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-44260,
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaab:1-40601|||
9fd890c7-3ec1-11eb-a87b-70b5e831c9f8---:1-44260---:44260
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-44260,
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaab:1-40601|||
9cddd7e3-3ec1-11eb-81a5-70b5e831c9f8---:1-44260---:44260
/////////////2////////////// 
//////////////1///////////// 
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-44258,
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaab:1-40601|||
a2dd6444-3ec1-11eb-9576-70b5e831c9f8---:---:0
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-44260,
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaab:1-40601|||
9cddd7e3-3ec1-11eb-81a5-70b5e831c9f8---:---:0
/////////////2////////////// 
//////////////1///////////// 
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-44258,
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaab:1-40601|||
a2dd6444-3ec1-11eb-9576-70b5e831c9f8---:---:0
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-44260,
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaab:1-40601|||
9fd890c7-3ec1-11eb-a87b-70b5e831c9f8---:---:0
/////////////2////////////// 












--------------------------------------
uuid: 9cddd7e3-3ec1-11eb-81a5-70b5e831c9f8
role: 1
group_name: 
member_id(): 127.0.0.1:24901
member_weight: 50
gtid_executed: aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-44265,
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaab:1-40601
gtid_purged: 
gtid_retrieved: aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-44265,
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaab:1-40601
++++++++++++++++++++++++++++++++++++
uuid: 9fd890c7-3ec1-11eb-a87b-70b5e831c9f8
role: 2
group_name: aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa
member_id(): 127.0.0.1:24902
member_weight: 50
gtid_executed: aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-44265,
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaab:1-40601
gtid_purged: 
gtid_retrieved: aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-44253:44255-44258:44260-44261:44263:44265,
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaab:2-40601
++++++++++++++++++++++++++++++++++++
uuid: a2dd6444-3ec1-11eb-9576-70b5e831c9f8
role: 2
group_name: 
member_id(): 127.0.0.1:24903
member_weight: 50
gtid_executed: aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-44261,
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaab:1-40601
gtid_purged: 
gtid_retrieved: aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-44253:44256-44258:44261,
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaab:3-40601
++++++++++++++++++++++++++++++++++++
--------------------------------------
//////////////1///////////// 
group_name::aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-44265,aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaab:1-40601|||
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-44265,
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaab:1-40601|||
//////////////1///////////// 
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-44265,
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaab:1-40601|||
9fd890c7-3ec1-11eb-a87b-70b5e831c9f8---:1-44265---:44265
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-44265,
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaab:1-40601|||
9cddd7e3-3ec1-11eb-81a5-70b5e831c9f8---:1-44265---:44265
/////////////2////////////// 
//////////////1///////////// 
group_name::aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-44265,aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaab:1-40601|||
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-44265,
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaab:1-40601|||
//////////////1///////////// 
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-44265,
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaab:1-40601|||
9fd890c7-3ec1-11eb-a87b-70b5e831c9f8---:1-44265---:44265
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-44265,
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaab:1-40601|||
9cddd7e3-3ec1-11eb-81a5-70b5e831c9f8---:1-44265---:44265
/////////////2////////////// 
//////////////1///////////// 
group_name::
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-44261,aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaab:1-40601|||
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-44265,
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaab:1-40601|||
//////////////1///////////// 
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-44261,
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaab:1-40601|||
a2dd6444-3ec1-11eb-9576-70b5e831c9f8---:---:0
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-44265,
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaab:1-40601|||
9cddd7e3-3ec1-11eb-81a5-70b5e831c9f8---:---:0
/////////////2////////////// 
//////////////1///////////// 
group_name::
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-44261,aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaab:1-40601|||
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-44265,
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaab:1-40601|||
//////////////1///////////// 
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-44261,
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaab:1-40601|||
a2dd6444-3ec1-11eb-9576-70b5e831c9f8---:---:0
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-44265,
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaab:1-40601|||
9fd890c7-3ec1-11eb-a87b-70b5e831c9f8---:---:0
/////////////2//////////

#### subset 判断错误
this member id: 127.0.0.1:24903
other member id: 127.0.0.1:24901
this executed gtid: aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-56524
other executed gtid: aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-56523,
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaab:1
this_Gtid_set: aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-56524
other_Gtid_set: aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-56523,
aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaab:1
other_Gtid_set is equal to this_Gtid_set


This member has more executed transactions than those present in the group. Local transactions: 4eb182af-40e4-11eb-9e4c-70b5e831c9f8:1-4 > Group transactions: aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-56533'


+---------------------------+----------------------+--------------------------------------+-----------------------------+----------------------------+--------------------------+------------------------------------+----------------------------------------------+--------------------------------+--------------------------------------------+-----------------------------------+-----------------------------------+-----------------------------------+
| CHANNEL_NAME              | VIEW_ID              | MEMBER_ID                            | COUNT_TRANSACTIONS_IN_QUEUE | COUNT_TRANSACTIONS_CHECKED | COUNT_CONFLICTS_DETECTED | COUNT_TRANSACTIONS_ROWS_VALIDATING | TRANSACTIONS_COMMITTED_ALL_MEMBERS           | LAST_CONFLICT_FREE_TRANSACTION | COUNT_TRANSACTIONS_REMOTE_IN_APPLIER_QUEUE | COUNT_TRANSACTIONS_REMOTE_APPLIED | COUNT_TRANSACTIONS_LOCAL_PROPOSED | COUNT_TRANSACTIONS_LOCAL_ROLLBACK |
+---------------------------+----------------------+--------------------------------------+-----------------------------+----------------------------+--------------------------+------------------------------------+----------------------------------------------+--------------------------------+--------------------------------------------+-----------------------------------+-----------------------------------+-----------------------------------+
| group_replication_applier | 16082621393425631:15 | b98d4c21-3f66-11eb-bf8c-70b5e831c9f8 |                           0 |                          0 |                        0 |                                  0 | aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-56537 |                                |                                          0 |                                 5 |                                 0 |                                 0 |
| group_replication_applier | 16082621393425631:15 | bcaadacf-3f66-11eb-8414-70b5e831c9f8 |                           0 |                          0 |                        0 |                                  0 | aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-56537 |                                |                                          0 |                                 7 |                                 0 |                                 0 |
| group_replication_applier | 16082621393425631:15 | c91c5e26-40e6-11eb-a6d7-70b5e831c9f8 |                           1 |                          0 |                        0 |                                  0 |                                              |                                |                                          0 |                                 0 |                                 0 |                                 0 |
+---------------------------+----------------------+--------------------------------------+-----------------------------+----------------------------+--------------------------+------------------------------------+----------------------------------------------+--------------------------------+--------------------------------------------+-----------------------------------+-----------------------------------+-----------------------------------+
3 rows in set (0.00 sec)


#### 三节点连接
zhaoguodong@zhaoguodong-OptiPlex-5070:~/msBuild/mysql-8.0.22/bld/runtime_output_directory$ sudo netstat -nap | grep 3187
[sudo] password for zhaoguodong: 
tcp        0      0 127.0.0.1:52504         127.0.0.1:24902         ESTABLISHED 3187/./mysqld       
tcp        0      0 127.0.0.1:37934         127.0.0.1:24903         ESTABLISHED 3187/./mysqld       
tcp        0      0 127.0.0.1:57994         127.0.0.1:24901         ESTABLISHED 3187/./mysqld       
tcp6       0      0 :::24802                :::*                    LISTEN      3187/./mysqld       
tcp6       0      0 :::24902                :::*                    LISTEN      3187/./mysqld       
tcp6       0      0 127.0.0.1:24902         127.0.0.1:52504         ESTABLISHED 3187/./mysqld       
tcp6       0      0 127.0.0.1:24902         127.0.0.1:32896         ESTABLISHED 3187/./mysqld       
tcp6       0      0 127.0.0.1:24902         127.0.0.1:53612         ESTABLISHED 3187/./mysqld       
unix  2      [ ACC ]     STREAM     LISTENING     328319   3187/./mysqld        /usr/local/mysql/datas/s2/s2.sock
unix  3      [ ]         STREAM     CONNECTED     33187    1528/dbus-daemon     /run/user/1000/bus
zhaoguodong@zhaoguodong-OptiPlex-5070:~/msBuild/mysql-8.0.22/bld/runtime_output_directory$ sudo netstat -nap | grep 7575
tcp        0      0 127.0.0.1:32896         127.0.0.1:24902         ESTABLISHED 7575/./mysqld       
tcp        0      0 127.0.0.1:57986         127.0.0.1:24901         ESTABLISHED 7575/./mysqld       
tcp        0      0 127.0.0.1:45456         127.0.0.1:24903         ESTABLISHED 7575/./mysqld       
tcp6       0      0 :::24801                :::*                    LISTEN      7575/./mysqld       
tcp6       0      0 :::24901                :::*                    LISTEN      7575/./mysqld       
tcp6       0      0 127.0.0.1:24901         127.0.0.1:57992         ESTABLISHED 7575/./mysqld       
tcp6       0      0 127.0.0.1:24901         127.0.0.1:57986         ESTABLISHED 7575/./mysqld       
tcp6       0      0 127.0.0.1:24901         127.0.0.1:57994         ESTABLISHED 7575/./mysqld       
unix  2      [ ACC ]     STREAM     LISTENING     1854221  7575/./mysqld        /usr/local/mysql/datas/s1/s1.sock
zhaoguodong@zhaoguodong-OptiPlex-5070:~/msBuild/mysql-8.0.22/bld/runtime_output_directory$ sudo netstat -nap | grep 14069
tcp        0      0 127.0.0.1:53612         127.0.0.1:24902         ESTABLISHED 14069/./mysqld      
tcp        0      0 127.0.0.1:57992         127.0.0.1:24901         ESTABLISHED 14069/./mysqld      
tcp        0      0 127.0.0.1:37926         127.0.0.1:24903         ESTABLISHED 14069/./mysqld      
tcp6       0      0 :::24803                :::*                    LISTEN      14069/./mysqld      
tcp6       0      0 :::24903                :::*                    LISTEN      14069/./mysqld      
tcp6       0      0 127.0.0.1:24903         127.0.0.1:37934         ESTABLISHED 14069/./mysqld      
tcp6       0      0 127.0.0.1:24903         127.0.0.1:37926         ESTABLISHED 14069/./mysqld      
tcp6       0      0 127.0.0.1:24903         127.0.0.1:45456         ESTABLISHED 14069/./mysqld      
unix  2      [ ACC ]     STREAM     LISTENING     684979   14069/./mysqld       /usr/local/mysql/datas/s3/s3.sock
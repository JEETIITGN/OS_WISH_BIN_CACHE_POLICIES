cd /home/jeet/Async_Priority/compile_loc/tnoc/sim/router_data_width_64_vc_2/
[exec csh]
source ~/bashrc_synopsys
make clean; make DUMP=vpd
cd tnoc_router_sample_test/
dve -full64 -vpd dump.vpd

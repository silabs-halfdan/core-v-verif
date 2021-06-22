1. Update paths to point to compiler supporting the B extension
module gcc riscv32_10.2.0-rvb
setenv CV_SW_TOOLCHAIN /tool/gcc/riscv32_10.2.0-rvb/rhel7-64
setenv COREV_SW_TOOLCHAIN /tool/gcc/riscv32_10.2.0-rvb/rhel7-64

2. Update the checked out version of E40X:
cd core-v-cores/cv32e40x
git checkout f7ae600597ea70fa683919f9fe7d7553eff29c83

3.
Update the localparam in core-v-cores/cv32e40x/rtl/cv32e40x_core.sv to include B extension:
localparam b_ext_e B_EXT       = ZBA_ZBB_ZBS;

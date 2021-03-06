/* This code generates the following warning in 3.10-rc5
[   44.688044] ------------[ cut here ]------------
[   44.692023] WARNING: at kernel/events/core.c:2122 task_ctx_sched_out+0x3c/0x5f()
[   44.692023] Modules linked in: nfsd auth_rpcgss oid_registry nfs_acl nfs lockd dns_resolver fscache sunrpc loop fuse snd_hda_codec_hdmi snd_hda_codec_realtek coretemp kvm_intel kvm nouveau mxm_wmi evdev ttm microcode drm_kms_helper drm i2c_algo_bit video wmi snd_hda_intel acpi_cpufreq snd_hda_codec mperf snd_hwdep snd_pcm snd_page_alloc snd_seq snd_seq_device snd_timer shpchp snd soundcore button psmouse pcspkr processor i2c_nforce2 thermal_sys serio_raw i2c_core ext4 crc16 jbd2 mbcache sg sd_mod crc_t10dif ata_generic ahci libahci ohci_hcd libata ehci_pci ehci_hcd r8169 mii scsi_mod usbcore usb_common
[   44.692023] CPU: 0 PID: 2992 Comm: out Not tainted 3.10.0-rc5 #2
[   44.692023] Hardware name: AOpen   DE7000/nMCP7ALPx-DE R1.06 Oct.19.2012, BIOS 080015  10/19/2012
[   44.692023]  0000000000000000 ffffffff8102e215 0000000000000000 ffff88011fc15b28
[   44.692023]  ffff8801165a10c0 0000000000000000 ffff88011977458c ffffffff810ab2e1
[   44.692023]  ffff880119774580 ffffffff810af04e 0000000000000009 ffff8801165a10c0
[   44.692023] Call Trace:
[   44.692023]  [<ffffffff8102e215>] ? warn_slowpath_common+0x5b/0x70
[   44.692023]  [<ffffffff810ab2e1>] ? task_ctx_sched_out+0x3c/0x5f
[   44.692023]  [<ffffffff810af04e>] ? perf_event_exit_task+0xbf/0x194
[   44.692023]  [<ffffffff81032a37>] ? do_exit+0x3e7/0x90c
[   44.692023]  [<ffffffff810cd5cf>] ? __do_fault+0x359/0x394
[   44.692023]  [<ffffffff81032fe6>] ? do_group_exit+0x66/0x98
[   44.692023]  [<ffffffff8103dbcd>] ? get_signal_to_deliver+0x479/0x4ad
[   44.692023]  [<ffffffff810cdd24>] ? __pte_alloc+0x83/0xf2
[   44.692023]  [<ffffffff8100205d>] ? do_signal+0x3c/0x432
[   44.692023]  [<ffffffff81368160>] ? __do_page_fault+0x31c/0x3ba
[   44.692023]  [<ffffffff81002473>] ? do_notify_resume+0x20/0x5d
[   44.692023]  [<ffffffff813655b5>] ? retint_signal+0x3d/0x78
[   44.692023] ---[ end trace 38bad7d3252e7847 ]---
*/

/* reported to lkml https://lkml.org/lkml/2013/6/12/534 */

/* Possibly fixed by 734df5ab549ca44f40de0f07af1c8803856dfb18 */
/* in 3.11-rc1 */

/* Generated by the perf_fuzzer */

/* by Vince Weaver <vincent.weaver _at_ maine.edu */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <sys/ioctl.h>
#include <sys/prctl.h>

#include "hw_breakpoint.h"
#include "perf_event.h"

#include "perf_helpers.h"

int fd[1024];
struct perf_event_attr pe[1024];
char *mmap_result[1024];

int forked_pid;

int main(int argc, char **argv) {

	memset(&pe[20],0,sizeof(struct perf_event_attr));
	pe[20].type=PERF_TYPE_SOFTWARE;
	pe[20].config=PERF_COUNT_SW_TASK_CLOCK;
	pe[20].sample_type=0; /* 0 */
	pe[20].read_format=0x0ULL; /* 0 */
	pe[20].inherit=1;
	pe[20].pinned=1;
	pe[20].exclusive=1;
	pe[20].exclude_user=1;
	pe[20].exclude_kernel=1;
	pe[20].exclude_hv=1;
	pe[20].inherit_stat=1;
	pe[20].precise_ip=0; /* arbitrary skid */
	pe[20].exclude_guest=1;
	pe[20].wakeup_events=0;
	pe[20].bp_type=HW_BREAKPOINT_EMPTY;

	fd[20]=perf_event_open(&pe[20],0,0,-1,(long)0x20000000000000ULL /*20000000000000*/ );


	memset(&pe[23],0,sizeof(struct perf_event_attr));
	pe[23].type=PERF_TYPE_TRACEPOINT;
	pe[23].size=96;
	pe[23].config=0x1d;
	pe[23].sample_type=0; /* 0 */
	pe[23].read_format=PERF_FORMAT_TOTAL_TIME_RUNNING|PERF_FORMAT_GROUP; /* a */
	pe[23].exclude_user=1;
	pe[23].exclude_hv=1;
	pe[23].comm=1;
	pe[23].inherit_stat=1;
	pe[23].enable_on_exec=1;
	pe[23].precise_ip=0; /* arbitrary skid */
	pe[23].exclude_host=1;
	pe[23].exclude_guest=1;
	pe[23].wakeup_events=0;
	pe[23].bp_type=HW_BREAKPOINT_EMPTY;
	pe[23].config1=0x26;

	fd[23]=perf_event_open(&pe[23],0,0,-1,0 /*0*/ );


	memset(&pe[12],0,sizeof(struct perf_event_attr));
	pe[12].type=PERF_TYPE_SOFTWARE;
	pe[12].size=96;
	pe[12].config=PERF_COUNT_SW_TASK_CLOCK;
	pe[12].sample_type=0; /* 0 */
	pe[12].read_format=PERF_FORMAT_ID; /* 4 */
	pe[12].inherit=1;
	pe[12].exclude_kernel=1;
	pe[12].exclude_idle=1;
	pe[12].mmap=1;
	pe[12].freq=1;
	pe[12].task=1;
	pe[12].watermark=1;
	pe[12].precise_ip=1; /* constant skid */
	pe[12].sample_id_all=1;
	pe[12].exclude_host=1;
	pe[12].wakeup_watermark=0;
	pe[12].bp_type=HW_BREAKPOINT_EMPTY;

	fd[12]=perf_event_open(&pe[12],0,0,fd[23],PERF_FLAG_FD_NO_GROUP /*1*/ );


	memset(&pe[30],0,sizeof(struct perf_event_attr));
	pe[30].type=PERF_TYPE_HARDWARE;
	pe[30].size=72;
	pe[30].config=PERF_COUNT_HW_INSTRUCTIONS;
	pe[30].sample_type=0; /* 0 */
	pe[30].read_format=PERF_FORMAT_TOTAL_TIME_ENABLED|PERF_FORMAT_ID; /* 5 */
	pe[30].exclude_user=1;
	pe[30].exclude_hv=1;
	pe[30].mmap=1;
	pe[30].comm=1;
	pe[30].freq=1;
	pe[30].task=1;
	pe[30].watermark=1;
	pe[30].precise_ip=2; /* request zero skid */
	pe[30].sample_id_all=1;
	pe[30].wakeup_watermark=0;
	pe[30].bp_type=HW_BREAKPOINT_EMPTY;

	fd[30]=perf_event_open(&pe[30],0,0,fd[20],0 /*0*/ );


	memset(&pe[11],0,sizeof(struct perf_event_attr));
	pe[11].type=PERF_TYPE_SOFTWARE;
	pe[11].size=64;
	pe[11].config=PERF_COUNT_SW_TASK_CLOCK;
	pe[11].sample_type=0; /* 0 */
	pe[11].read_format=PERF_FORMAT_TOTAL_TIME_ENABLED|PERF_FORMAT_GROUP; /* 9 */
	pe[11].exclude_idle=1;
	pe[11].comm=1;
	pe[11].enable_on_exec=1;
	pe[11].task=1;
	pe[11].watermark=1;
	pe[11].precise_ip=0; /* arbitrary skid */
	pe[11].exclude_host=1;
	pe[11].exclude_guest=1;
	pe[11].wakeup_watermark=0;
	pe[11].bp_type=HW_BREAKPOINT_EMPTY;

	fd[11]=perf_event_open(&pe[11],0,0,fd[23],PERF_FLAG_FD_NO_GROUP|PERF_FLAG_FD_OUTPUT /*3*/ );

	forked_pid=fork();
	if (forked_pid==0) while(1);
	close(fd[23]);
	kill(forked_pid,SIGKILL);
	/* Replayed 8 syscalls */
	return 0;
}


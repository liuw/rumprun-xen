#include <mini-os/console.h>

#include <errno.h>

#define STUB(name)				\
  int name(void); int name(void) {		\
	static int done = 0;			\
	errno = ENOTSUP;			\
	if (done) return ENOTSUP; done = 1;	\
	minios_printk("STUB ``%s'' called\n", #name);	\
	return ENOTSUP;}

#define WEAK_STUB(name)				\
  int name(void) __attribute__((weak)); int name(void) {		\
	static int done = 0;			\
	errno = ENOTSUP;			\
	if (done) return ENOTSUP; done = 1;	\
	minios_printk("STUB ``%s'' called\n", #name);	\
	return ENOTSUP;}

STUB(__sigaction14);
STUB(__sigaction_sigtramp);
STUB(__getrusage50);

// STUB(__wait450);
STUB(__fork);
STUB(__vfork14);
STUB(execve);
STUB(kill);
STUB(getpriority);
STUB(setpriority);

// STUB(_sys___aio_suspend50)
// STUB(_sys___kevent50)
STUB(_sys___mq_timedreceive50)
STUB(_sys___mq_timedsend50)
STUB(_sys___msync13)
// STUB(_sys___nanosleep50)
// STUB(_sys___pollts50)
// STUB(_sys___pselect50)
// STUB(_sys___select50)
STUB(_sys___sigsuspend14)
STUB(_sys___wait450)
// STUB(_sys_accept)
// STUB(_sys_close)
// STUB(_sys_connect)
// STUB(_sys_fcntl)
// STUB(_sys_fdatasync)
// STUB(_sys_fsync)
// STUB(_sys_fsync_range)
STUB(_sys_mq_receive)
STUB(_sys_mq_send)
STUB(_sys_msgrcv)
STUB(_sys_msgsnd)
// STUB(_sys_open)
// STUB(_sys_poll)
// STUB(_sys_pread)
// STUB(_sys_pwrite)
// STUB(_sys_read)
// STUB(_sys_readv)
// STUB(_sys_write)
// STUB(_sys_writev)
WEAK_STUB(__sigtimedwait50) // XXX conflict with pthread_cancelstub
STUB(____sigtimedwait50)

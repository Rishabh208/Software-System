//Name:19_a_b_c.c
//Author:Rishabh Kumar Singh
//Roll No.:MT2024125
//Date:20 Sep 2024

// 19. Create a FIFO file by
// a. mknod command
// b. mkfifo command
// c. use strace command to find out, which command (mknod or mkfifo) is better.
// d. mknod system call
// e. mkfifo library function


// a. mknod myfifo1

// b. mkfifo myfifo2


//c. strace mknod mfifo1 p
// execve("/usr/bin/mknod", ["mknod", "mfifo1", "p"], 0x7ffd820b9c90 /* 46 vars */) = 0
// brk(NULL)                               = 0x556c80409000
// arch_prctl(0x3001 /* ARCH_??? */, 0x7ffd836043e0) = -1 EINVAL (Invalid argument)
// mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f300e36f000
// access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
// openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
// newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=64183, ...}, AT_EMPTY_PATH) = 0
// mmap(NULL, 64183, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7f300e35f000
// close(3)                                = 0
// openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libselinux.so.1", O_RDONLY|O_CLOEXEC) = 3
// read(3, "\177ELF\2\1\1\0\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\0\0\0\0\0\0\0\0"..., 832) = 832
// newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=174472, ...}, AT_EMPTY_PATH) = 0
// mmap(NULL, 181928, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7f300e332000
// mmap(0x7f300e338000, 114688, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x6000) = 0x7f300e338000
// mmap(0x7f300e354000, 28672, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x22000) = 0x7f300e354000
// mmap(0x7f300e35b000, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x29000) = 0x7f300e35b000
// mmap(0x7f300e35d000, 5800, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7f300e35d000
// close(3)                                = 0
// openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
// read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0P<\2\0\0\0\0\0"..., 832) = 832
// pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
// newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=2072888, ...}, AT_EMPTY_PATH) = 0
// pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
// mmap(NULL, 2117488, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7f300e000000
// mmap(0x7f300e022000, 1540096, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x22000) = 0x7f300e022000
// mmap(0x7f300e19a000, 360448, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x19a000) = 0x7f300e19a000
// mmap(0x7f300e1f2000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1f1000) = 0x7f300e1f2000
// mmap(0x7f300e1f8000, 53104, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7f300e1f8000
// close(3)                                = 0
// openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libpcre2-8.so.0", O_RDONLY|O_CLOEXEC) = 3
// read(3, "\177ELF\2\1\1\0\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\0\0\0\0\0\0\0\0"..., 832) = 832
// newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=625344, ...}, AT_EMPTY_PATH) = 0
// mmap(NULL, 627472, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7f300e298000
// mmap(0x7f300e29a000, 438272, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x2000) = 0x7f300e29a000
// mmap(0x7f300e305000, 176128, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x6d000) = 0x7f300e305000
// mmap(0x7f300e330000, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x97000) = 0x7f300e330000
// close(3)                                = 0
// mmap(NULL, 12288, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f300e295000
// arch_prctl(ARCH_SET_FS, 0x7f300e295800) = 0
// set_tid_address(0x7f300e295ad0)         = 11737
// set_robust_list(0x7f300e295ae0, 24)     = 0
// rseq(0x7f300e296120, 0x20, 0, 0x53053053) = 0
// mprotect(0x7f300e1f2000, 16384, PROT_READ) = 0
// mprotect(0x7f300e330000, 4096, PROT_READ) = 0
// mprotect(0x7f300e35b000, 4096, PROT_READ) = 0
// mprotect(0x556c7ebe9000, 4096, PROT_READ) = 0
// mprotect(0x7f300e3a4000, 8192, PROT_READ) = 0
// prlimit64(0, RLIMIT_STACK, NULL, {rlim_cur=8192*1024, rlim_max=RLIM64_INFINITY}) = 0
// munmap(0x7f300e35f000, 64183)           = 0
// statfs("/sys/fs/selinux", 0x7ffd836043b0) = -1 ENOENT (No such file or directory)
// statfs("/selinux", 0x7ffd836043b0)      = -1 ENOENT (No such file or directory)
// getrandom("\x4b\x56\xcb\x36\xad\x0c\x1b\x44", 8, GRND_NONBLOCK) = 8
// brk(NULL)                               = 0x556c80409000
// brk(0x556c8042a000)                     = 0x556c8042a000
// openat(AT_FDCWD, "/proc/filesystems", O_RDONLY|O_CLOEXEC) = 3
// newfstatat(3, "", {st_mode=S_IFREG|0444, st_size=0, ...}, AT_EMPTY_PATH) = 0
// read(3, "nodev\tsysfs\nnodev\ttmpfs\nnodev\tbd"..., 1024) = 407
// read(3, "", 1024)                       = 0
// close(3)                                = 0
// access("/etc/selinux/config", F_OK)     = -1 ENOENT (No such file or directory)
// openat(AT_FDCWD, "/usr/lib/locale/locale-archive", O_RDONLY|O_CLOEXEC) = 3
// newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=5716304, ...}, AT_EMPTY_PATH) = 0
// mmap(NULL, 5716304, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7f300da00000
// close(3)                                = 0
// mknodat(AT_FDCWD, "mfifo1", S_IFIFO|0666) = 0
// close(1)                                = 0
// close(2)                                = 0
// exit_group(0)                           = ?
// +++ exited with 0 +++



// c. strace mknod mfifo2
// execve("/usr/bin/mkfifo", ["mkfifo", "fifo2"], 0x7ffc367f33d8 /* 46 vars */) = 0
// brk(NULL)                               = 0x5626481b3000
// arch_prctl(0x3001 /* ARCH_??? */, 0x7ffd1c3cd8d0) = -1 EINVAL (Invalid argument)
// mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f31157c9000
// access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
// openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
// newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=64183, ...}, AT_EMPTY_PATH) = 0
// mmap(NULL, 64183, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7f31157b9000
// close(3)                                = 0
// openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libselinux.so.1", O_RDONLY|O_CLOEXEC) = 3
// read(3, "\177ELF\2\1\1\0\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\0\0\0\0\0\0\0\0"..., 832) = 832
// newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=174472, ...}, AT_EMPTY_PATH) = 0
// mmap(NULL, 181928, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7f311578c000
// mmap(0x7f3115792000, 114688, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x6000) = 0x7f3115792000
// mmap(0x7f31157ae000, 28672, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x22000) = 0x7f31157ae000
// mmap(0x7f31157b5000, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x29000) = 0x7f31157b5000
// mmap(0x7f31157b7000, 5800, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7f31157b7000
// close(3)                                = 0
// openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
// read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0P<\2\0\0\0\0\0"..., 832) = 832
// pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
// newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=2072888, ...}, AT_EMPTY_PATH) = 0
// pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
// mmap(NULL, 2117488, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7f3115400000
// mmap(0x7f3115422000, 1540096, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x22000) = 0x7f3115422000
// mmap(0x7f311559a000, 360448, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x19a000) = 0x7f311559a000
// mmap(0x7f31155f2000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1f1000) = 0x7f31155f2000
// mmap(0x7f31155f8000, 53104, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7f31155f8000
// close(3)                                = 0
// openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libpcre2-8.so.0", O_RDONLY|O_CLOEXEC) = 3
// read(3, "\177ELF\2\1\1\0\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\0\0\0\0\0\0\0\0"..., 832) = 832
// newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=625344, ...}, AT_EMPTY_PATH) = 0
// mmap(NULL, 627472, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7f31156f2000
// mmap(0x7f31156f4000, 438272, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x2000) = 0x7f31156f4000
// mmap(0x7f311575f000, 176128, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x6d000) = 0x7f311575f000
// mmap(0x7f311578a000, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x97000) = 0x7f311578a000
// close(3)                                = 0
// mmap(NULL, 12288, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f31156ef000
// arch_prctl(ARCH_SET_FS, 0x7f31156ef800) = 0
// set_tid_address(0x7f31156efad0)         = 11813
// set_robust_list(0x7f31156efae0, 24)     = 0
// rseq(0x7f31156f0120, 0x20, 0, 0x53053053) = 0
// mprotect(0x7f31155f2000, 16384, PROT_READ) = 0
// mprotect(0x7f311578a000, 4096, PROT_READ) = 0
// mprotect(0x7f31157b5000, 4096, PROT_READ) = 0
// mprotect(0x562646dc7000, 4096, PROT_READ) = 0
// mprotect(0x7f31157fe000, 8192, PROT_READ) = 0
// prlimit64(0, RLIMIT_STACK, NULL, {rlim_cur=8192*1024, rlim_max=RLIM64_INFINITY}) = 0
// munmap(0x7f31157b9000, 64183)           = 0
// statfs("/sys/fs/selinux", 0x7ffd1c3cd8a0) = -1 ENOENT (No such file or directory)
// statfs("/selinux", 0x7ffd1c3cd8a0)      = -1 ENOENT (No such file or directory)
// getrandom("\x4c\x47\xb6\x0b\x10\x07\x7a\x66", 8, GRND_NONBLOCK) = 8
// brk(NULL)                               = 0x5626481b3000
// brk(0x5626481d4000)                     = 0x5626481d4000
// openat(AT_FDCWD, "/proc/filesystems", O_RDONLY|O_CLOEXEC) = 3
// newfstatat(3, "", {st_mode=S_IFREG|0444, st_size=0, ...}, AT_EMPTY_PATH) = 0
// read(3, "nodev\tsysfs\nnodev\ttmpfs\nnodev\tbd"..., 1024) = 407
// read(3, "", 1024)                       = 0
// close(3)                                = 0
// access("/etc/selinux/config", F_OK)     = -1 ENOENT (No such file or directory)
// openat(AT_FDCWD, "/usr/lib/locale/locale-archive", O_RDONLY|O_CLOEXEC) = 3
// newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=5716304, ...}, AT_EMPTY_PATH) = 0
// mmap(NULL, 5716304, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7f3114e00000
// close(3)                                = 0
// mknodat(AT_FDCWD, "fifo2", S_IFIFO|0666) = 0
// close(1)                                = 0
// close(2)                                = 0
// exit_group(0)                           = ?
// +++ exited with 0 +++

// The mkfifo command is generally more specialized for creating FIFOs, while mknod can be used for various device types.

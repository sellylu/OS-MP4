/**************************************************************
 *
 * userprog/ksyscall.h
 *
 * Kernel interface for systemcalls 
 *
 * by Marcus Voelp  (c) Universitaet Karlsruhe
 *
 **************************************************************/

#ifndef __USERPROG_KSYSCALL_H__ 
#define __USERPROG_KSYSCALL_H__ 

#include "kernel.h"

#include "synchconsole.h"


void SysHalt()
{
  kernel->interrupt->Halt();
}

int SysAdd(int op1, int op2)
{
  return op1 + op2;
}
int SysCreate(char *filename, int size)
{
	return kernel->interrupt->CreateFile(filename, size);
}
int SysOpen(char *name)
{
	return kernel->interrupt->Open(name);
}
int SysWrite(int buf_add, int buf_size, int tid)
{
	return kernel->interrupt->Write(buf_add,buf_size,tid);
}
int SysRead(int buf_add, int buf_size, int tid)
{
	return kernel->interrupt->Read(buf_add, buf_size, tid);
}
int SysClose(int deleteid)
{
	return kernel->interrupt->Close(deleteid);
}
#ifdef FILESYS_STUB
int SysCreate(char *filename)
{
	// return value
	// 1: success
	// 0: failed
	return kernel->interrupt->CreateFile(filename);
}
#endif


#endif /* ! __USERPROG_KSYSCALL_H__ */

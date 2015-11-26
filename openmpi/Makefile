hw1: homework1
	mpirun --mca btl_tcp_if_exclude lo,eth0 -np 2 --hostfile machinefile /shared/hw1
homework1: 
	mpicc tarea1mpi.c -o /shared/hw1
hw2: deadlock
	mpirun --mca btl_tcp_if_exclude lo,eth0 -np 2 --hostfile machinefile /shared/hw2
deadlock: 
	mpicc deadlock.c -o /shared/hw2
hw3: deadlocksend
	mpirun --mca btl_tcp_if_exclude lo,eth0 -np 2 --hostfile machinefile /shared/hw3
deadlocksend: 
	mpicc deadlocksend.c -o /shared/hw3
hw4: deadlocksendrecv
	mpirun --mca btl_tcp_if_exclude lo,eth0 -np 2 --hostfile machinefile /shared/hw4
deadlocksendrecv: 
	mpicc deadlocksendrecv.c -o /shared/hw4
hw5: mpiExample4
	mpirun --mca btl_tcp_if_exclude lo,eth0 -np 4 --hostfile machinefile /shared/ex4
mpiExample4: 
	mpicc mpiExample4.c -o /shared/ex4
hw6: mpiExample7
	mpirun --mca btl_tcp_if_exclude lo,eth0 -np 4 --hostfile machinefile /shared/ex7
mpiExample7: 
	mpicc mpiExample7.c -o /shared/ex7

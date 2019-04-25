import java.util.concurrent.Semaphore;
import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;
public class ReaderWriter
{
	static Semaphore writeLock = new Semaphore(1);
	static Semaphore readLock = new Semaphore(1);
	static int readCount = 0;
	static int n = 0;
	static ArrayList<Integer> arr = new ArrayList<Integer>();
	static Scanner var = new Scanner(System.in);
	
	static class Write implements Runnable
	{
		public void run()
		{
			try
			{
				writeLock.acquire();
				System.out.println(Thread.currentThread().getName() + " Is Writing");
				for(int i = 0; i < n; i++)
				{
					int temp;
					temp = var.nextInt();
					arr.add(temp);
				}
				
				System.out.println("Data in Buffer: ");
				for(int i = 0; i < arr.size(); i++)
				{
					System.out.print(arr.get(i) + " ");
				}
				System.out.println();
				Thread.sleep(1000);
				System.out.println(Thread.currentThread().getName() + " Has Finished Writing");
				writeLock.release();
				
			}
			catch(InterruptedException e)
			{
				System.out.println(e.getMessage());
			}
		}
	}
	
	static class Read implements Runnable
	{
		public void run()
		{
			try
			{
				readLock.acquire();
				readCount++;
				if(readCount == 1)
				{
					writeLock.acquire();
				}
				
				readLock.release();
				
				Random random = new Random();
				int rand = random.nextInt(arr.size());
				
				System.out.println(Thread.currentThread().getName() + " Is Reading " + arr.get(rand));
				
				Thread.sleep(1500);
				System.out.println(Thread.currentThread().getName() + " Has Finished Reading");
				
				readLock.acquire();
				readCount--;
				if(readCount == 0)
				{
					writeLock.release();
				}
				
				readLock.release();
				
			}
			catch(InterruptedException e)
			{
				System.out.println(e.getMessage());
			}
		}
	}
	
	
	
	
	
	
	
	
	public static void main(String args[])
	{
		
		System.out.println("Number of Readers : ");
		n = var.nextInt();
		
		Read reader = new Read();
		Write writer = new Write();
	
		Thread t1 = new Thread(reader);
		Thread t2 = new Thread(reader);
		Thread t3 = new Thread(writer);
		Thread t4 = new Thread(reader);
		Thread t5 = new Thread(reader);
		Thread t6 = new Thread(writer);
		Thread t7 = new Thread(reader);
		
		t1.setName("Reader1");
		t2.setName("Reader2");
		t3.setName("Writer3");
		t4.setName("Reader4");
		t5.setName("Reader2");
		
		t3.start();
		t2.start();
		t4.start();
		t5.start();
		t6.start();
		t7.start();
		
		
		
		
		
	}

}



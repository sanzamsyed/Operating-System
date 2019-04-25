package WorkingExampleOfProducerConsumer;

import java.util.ArrayList;
import java.util.Scanner;

public class Process
{
	ArrayList<Integer> myList = new ArrayList<>();
	Scanner var = new Scanner(System.in);
	int capacity;
	int producedItem = 0;
	int consumedItem = 0;
	Object lock = new Object();
	
	public Process()
	{
		
	}
	
	public Process(int capacity)
	{
		this.capacity = capacity;
	}
	
	
	public void Produce()
	{
		while(true)
		{
			synchronized(lock)
			{
				while(myList.size() == capacity)
				{
					try {
					lock.wait();
					} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
					}
				}
				myList.add(producedItem);
				System.out.println("Producer produced Item : " + producedItem);
				producedItem++;
				lock.notify();
				try {
					Thread.sleep(1000);
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				}
		}
		
	}
	
	public void Consume()
	{
		while(true)
		{
			synchronized(lock)
			{
			while(myList.size() == 0)
			{
				try {
					lock.wait();
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			consumedItem = myList.remove(0);
			System.out.println("Consumer consumed item " + consumedItem);
			lock.notify();
			
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			}
		}
		
		
	}

}

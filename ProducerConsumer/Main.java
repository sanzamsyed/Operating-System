package WorkingExampleOfProducerConsumer;

import java.util.Scanner;

public class MainClass
{
	public static void main(String args[])
	{
		System.out.println("Capacity : ");
		Scanner var = new Scanner(System.in);
		
		int capacity = var.nextInt();
		
		Process p = new Process(capacity);
		
		Thread t1 = new Thread(new Runnable() {
			public void run()
			{
				p.Produce();
			}
		});
		
		Thread t2 = new Thread(new Runnable() {
			public void run()
			{
				p.Produce();
			}
		});
		
		Thread t3 = new Thread(new Runnable() {
			public void run()
			{
				p.Consume();
			}
		});
		
		t1.start();
		t2.start();
		t3.start();
		
	}

}

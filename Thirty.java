import java.util.*;
public class Thirty
{
	//there are only three #'s that can be written as 4th powers of their digits
	//1634 = 1^4 + 6^4 + 3^4 + 4^4 
	//find #'s that can be written as 5th powers of their digits
	public static int count;
	public static void main(String args[])
	{
		final long startTime = System.currentTimeMillis();
		try{
			int i = 2;
			while(i<200000)
			{
				calc(Integer.toString(i));
				i++;
			}
		}catch(Exception E)
		{
			System.out.println("max int exceeded");
		}
		final long endTime = System.currentTimeMillis();
		System.out.println(endTime-startTime);
		System.out.println(count);
	}
	public static void calc(String num)
	{
		int calc = 0;
		for(int i = 0; i<num.length(); i++)
		{
			calc += Math.pow(Character.getNumericValue(num.charAt(i)),5);
		}
		if(calc == Integer.parseInt(num))
		{	
			count += calc;
			//System.out.println(count);
		}
	}
}

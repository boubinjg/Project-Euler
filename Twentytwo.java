import java.io.*;
import java.util.*;
public class Twentytwo
{
	public static void main(String args[])
	{
		List<String> names;
		String s = "";
		try (BufferedReader br = new BufferedReader(new FileReader("22.txt"))) 
		{
			for(String line; (line = br.readLine())!= null;)
 			{	
				s+=line;	
			}	
		}catch(Exception e){}
		names = Arrays.asList(s.split(","));	
		java.util.Collections.sort(names);
		int temp = 0, tempsum = 0, sum = 0;
		for(int i = 0; i<names.size(); i++)
		{
			tempsum = 0;
			for(int j = 1; j<names.get(i).length()-1; j++)
			{
				temp = (int)names.get(i).charAt(j);
				tempsum += temp-64;
				//if(names.get(i).charAt(j) == 'A')
				//	System.out.println(tempSum);
			}
			tempsum *= i+1;
			sum += tempsum;
		}		
		System.out.println(sum);
	}
}


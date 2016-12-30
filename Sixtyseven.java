import java.io.*;
public class Sixtyseven
{
	public static void main(String args[])
	{
		int triangle[][] = new int[100][100];
		for(int i = 0; i<100; i++)
			for(int j = 0; j<100; j++)
			{
				triangle[i][j] = 0;
			}
		try (BufferedReader br = new BufferedReader(new FileReader("67.txt"))) 
		{
 			String line;
			String[] numbers;
			int y = 0;
    			while ((line = br.readLine()) != null) 
			{
       				numbers = line.split(" ");
				for(int x = 0; x<numbers.length; x++)
				{
					triangle[x][y] = Integer.parseInt(numbers[x]);
				}
				y++;
    			}
		}catch(Exception e){}
		
		for(int row = 98; row>=0; row--)
		{
			for(int col = 0; col<100; col++)
			{
				if(triangle[col][row] != 0){
					if(triangle[col][row+1]<triangle[col+1][row+1])
						triangle[col][row]+=triangle[col+1][row+1];
					else
						triangle[col][row]+=triangle[col][row+1];
					System.out.print(triangle[col][row]+ " ");
				}
			}
			System.out.println();
		}
	
	}
}


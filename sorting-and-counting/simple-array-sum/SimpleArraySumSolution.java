/* Data Structures in C++11 (and sometimes Java 8)
by Amanda Falke
*/

import java.io.*;
import java.util.*;

public class SimpleArraySumSolution {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		System.out.println("Enter in the size of the array.");
		int sizeOfArray = sc.nextInt();

		System.out.println("Enter in array numbers.");

		int store = 0;

		for(int i = 0; i<sizeOfArray;++i)
		{
				store += sc.nextInt();
		}
		sc.close();
		System.out.println(store);
	}
}

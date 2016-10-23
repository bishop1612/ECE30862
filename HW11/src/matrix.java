
import java.util.Random;
/**
 * Created by Bishop Sarkar on 10/13/2016.
 */

public class matrix {
	private int N;

	public matrix(int n) {
		N = n;
		// TODO Auto-generated constructor stub
	}
	
	/*
	 * Function checking the validilty of n
	 * */
	public static void check(int n) throws Exception{
		if(n%2!=0) {
            throw new Exception();
        }
	}
	
	/*
	 * Function forming the matrixes with random numbers
	 * */
	public int[][] formmatrix() {
		Random randomGenerator = new Random();
		int [][] formmatrix = new int[N][N];
		int i,j = 0;
		for(i = 0;i < N;i++){
			for(j = 0;j < N;j++){
				formmatrix[i][j] = randomGenerator.nextInt(100);
			}
		}
		return formmatrix;
		
	}
	
	/*
	 * Function to print matrixes
	 * */
	public void printmatrix(int [][] C, int n) {
		int i,j = 0;
		for(i = 0;i < n;i++){
			for(j = 0;j < n;j++){
				System.out.print(C[i][j] + " ");
			}
			System.out.println();
		}
		
	}

}

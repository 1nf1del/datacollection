import java.util.*;

class B1{

    public static void main(String[] args){
	Scanner sc=new Scanner(System.in);
	int T=sc.nextInt();
	for(int tt=1;tt<=T;tt++){
	    int E=sc.nextInt();int R=sc.nextInt();
	    int N=sc.nextInt();
	    int[] v=new int[N];
	    for(int i=0;i<N;i++)v[i]=sc.nextInt();
	    int[][] dp=new int[N+1][E+1];//dp[i][j]:i�Ԗڂ܂ŏI���Ďc��G�l���M�[j�ł̍ő剿�l��
	    int ans=-1;
	    for(int i=1;i<=N;i++){ 
		for(int j=0;j<=E;j++){//�O��܂ł̎c��G�l���M�[��
		    for(int k=0;k<=j;k++){ //�g���G�l���M�[��
			int e=Math.min(E,j-k+R);
			dp[i][j]=Math.max(dp[i][j],dp[i-1][e]+k*v[i-1]);
			ans=Math.max(ans,dp[i][j]);
		    }
		}
	    }
	    System.out.printf("Case #%d: %d\n",tt,ans);
	}
    }
}

       
		   
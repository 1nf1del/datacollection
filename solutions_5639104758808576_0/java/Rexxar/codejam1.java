import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class codejam1 {
   
    
    public static void main(String[] args)
    {
        String fileName = "A-small-attempt0.in";
        String line = null;
        String testCases;
        String array[] = new String[100];
        int a[] = new int[8];
        int size = 0;
        boolean flag = false;
        try{
            FileReader fileReader = new FileReader(fileName);
            BufferedReader bufferedReader = new BufferedReader(fileReader);
            testCases = bufferedReader.readLine();     
            while((line = bufferedReader.readLine()) != null) {
                array[size] = line;
                size++;
            }
            bufferedReader.close();
        }
        catch(Exception ex) {}
        for(int i=0 ; i<size; i++)
        {
            String temp = array[i].substring(2);
            int tempSize = temp.length();
            for(int j=0;j<tempSize;j++) {
                    a[j] = Integer.parseInt(String.valueOf(temp.charAt(j)));
            }
            if(tempSize == 1)
            {
                if(a[0]>0)
                {String temp1 = "Case #"+ (i+1) +": 0";
                   try{
                    write(temp1);
                    }catch(Exception e){}
                }
            }
            else
            {
                int tempS = 0;
                int extras = 0;
                for(int j=0;j<tempSize;j++)
                {
                     if(j>0)
                     {
                        if(a[j]!=0)
                       {    
                            if(j<=tempS)
                            {flag = true;
                            }else
                            {
                                extras = extras + j - tempS;
                                tempS += (j - tempS);
                            }
                       } 
                     }
                     tempS = tempS + a[j];
                }
                String temp1 = "Case #"+ (i+1) +": "+extras;
                    try{
                    write(temp1);
                    }catch(Exception e){}
        }
  
      }
        
    }
    
    static void write(String data) throws IOException
    {
        File file = new File("output.txt");
        if (!file.exists()) {
				file.createNewFile();
			}
        FileWriter fileWriter = new FileWriter(file,true);
        BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
        PrintWriter out = new PrintWriter(bufferedWriter);
        out.println(data);
        bufferedWriter.close();
    }
    
    
}

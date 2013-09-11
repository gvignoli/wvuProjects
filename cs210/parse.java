import  java.io.BufferedReader;
import  java.io.FileReader;
import java.io.*;
import java.util.regex.*;
import java.util.*;
import java.util.TreeMap;




public class parse {
  
  public static void main(String args[]) throws IOException {
    
    File path = new File("C:\\Users\\user\\Desktop\\JavaParser"); //this absolute path work though
    // File path = new File(".\\textfiles"); //this relative path should work!!
    int counter = 0;
    String files;
   // File folder = new File(path);
   // File textFile = new File(folder.getAbsolutePath() + File.separator + files);
    File[] listOfFiles = path.listFiles(); 
   // System.out.println(listOfFiles); just a testing line
    
    
    for (int i = 0; i < listOfFiles.length; i++) 
    {
      if (listOfFiles[i].isFile()) 
      {
        files = listOfFiles[i].getName();
        // counter++; just a testing line
        //System.out.println(counter); just a testing line 
       
     
   
          
          
    
    // System.out.println("Enter the name of the file to parse ");
    //  Scanner sc = new Scanner (System.in);
    //  String infile = sc.next();
    BufferedReader reader = new BufferedReader(new FileReader(files));
    // BufferedReader reader = new BufferedReader(new FileReader(infile)); backup of a line
    //  BufferedReader reader = new BufferedReader(new FileReader("C:\\Users\\user\\Desktop\\test.txt"));
    String line = null;
    
    
          FileWriter writer = new FileWriter("C:\\Users\\user\\Desktop\\output.csv");
    
    writer.append("Host Name");
    writer.append(',');
    writer.append("MAC");
    writer.append(',');
    writer.append("IP");
    writer.append(',');
    writer.append("OS");
    writer.append('\n');
    writer.flush();
    writer.close();
    
    int count = 0;
    int check = 0;
    int ita = 0;
    int itb =0;
    HashMap hm = new HashMap(); 
    ArrayList<String> myArr = new ArrayList<String>();
    
    
    while ((line = reader.readLine()) != null)
    {
      String stripped = line.trim();
      int len = stripped.length();
      
      
      if (stripped.indexOf("Host Name") != -1 || stripped.indexOf("IPv4 Address") != -1 || stripped.indexOf("OS Name") != -1 ||  stripped.indexOf("Physical Address") != -1 && ita<=1 &&  itb<=1)
      {
        count++;
        
        if(count<=8 )
        {
          
          String colon = stripped;
          String[] strings = colon.split(":");
          //  String strip = s
          
          String stringa = strings[0]; 
          System.out.println("This is string a " +stringa);
          String stringb = strings[1].trim();
          System.out.println("this is string b " +stringb);
          
          //if(isFound(stringb))
          // {System.out.println("HEYY IT FOUND IT>>>NOW USE IT MAN!!");
          //  }else System.out.println("IT FAILED" +stringb);
          String stringb1 = stringb.toLowerCase();
          
          hm.put(count, stringb1);
          
          
          
          
          Pattern p = Pattern.compile("^\\s([0-9A-F]{2}[:-]){5}([0-9A-F]{2})$");
          Matcher m = p.matcher(stringb1);
          //System.out.println(m.find());/this line is similar to the one below it
          // System.out.println(m.matches());//this line finds a valid mac address.
          
          
          
          if(hm.get(count).equals(hm.get(count-3)))
          {
            
            stringb1 = "";
           // System.out.println("MADE IT");
          }
          
          
          
          if(m.matches())
          {
            ita++;
          }
          
          
          
          System.out.println(stringb1);
          
          
          String last = stringb1;
          
          
          
          
          
          check++;
          
          
          ita++;
          itb++;
          
          generateCsvFile("C:\\Users\\user\\Desktop\\output.csv",last); 
          
        }
        
        
      }
      
      
    }
  }
  
    }
  }
  
  
  public static boolean isFound(String s){
    return s.matches("[a-zA-Z]");
    //just searching for letters , all ofem, both upper and lower case
  }
  
  private static void generateCsvFile(String sFileName, String string)
  {
    try
    {
      FileWriter writer = new FileWriter(sFileName,true);
      
      writer.append( string);
      writer.append(',');
      
      
      
      writer.flush();
      writer.close();
      
    }
    catch(IOException e)
    {
      e.printStackTrace();
    } 
  }
  
   }
    
  

 
  
  




 

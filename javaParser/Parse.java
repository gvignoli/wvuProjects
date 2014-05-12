//parsing computer spec page for useful information, then outputting to CSV file


import  java.io.BufferedReader;
import  java.io.FileReader;
import java.io.*;
import java.util.regex.*;
import java.util.*;





public class parse {

 
    public static void main(String args[]) throws IOException {
      
    System.out.println("Enter the name of the folder to parse (all files!): ");
    // "..\test2" is not a bad idea. 
    // "." or ".\" IS A BAD IDEA.
    // It doesn't like either the .class or the .java file. I'm guessing the .class.
    Scanner sc = new Scanner (System.in);
    String infolder = sc.next();
    File dir = new File(infolder);
    
    for (File child : dir.listFiles()) {
      if (!child.isFile()) continue;
      String infile = child.getAbsolutePath();
      

      BufferedReader reader = new BufferedReader(new FileReader(infile));
    
  String line = null;

  File outfiletest = new File("C:\\Users\\user\\Desktop\\output.csv");
  if(!outfiletest.exists()) { // Don't re-write the header every file, and don't overwrite (this was the issue).
     FileWriter writer = new FileWriter("C:\\Users\\user\\Desktop\\output.csv");
     writer.append("Service Tag");
     writer.append(',');
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
  } else { // Newline between records.
     FileWriter writer = new FileWriter("C:\\Users\\user\\Desktop\\output.csv",true);
     writer.append('\n');
     writer.flush();
     writer.close();
  }
  outfiletest = null;
  
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

    
      if (stripped.indexOf("service tag") != -1 || stripped.indexOf("Host Name") != -1 || stripped.indexOf("IPv4 Address") != -1 || stripped.indexOf("IP Address") != -1 ||    stripped.indexOf("OS Name") != -1 || stripped.indexOf("Physical Address") != -1 && ita<=2 &&  itb<=2)
      {
        count++;
       
        if(count<=8 )
        {
        
        String colon = stripped;
        String[] strings = colon.split(":");
      //  String strip = s
     
        String stringa = strings[0]; 
        String stringb = strings[1].trim(); 
   
       String stringb1 = stringb.toLowerCase();
        
        hm.put(count, stringb1);
       
        
     
        
        Pattern p = Pattern.compile("^\\s([0-9A-F]{2}[:-]){5}([0-9A-F]{2})$");
        Matcher m = p.matcher(stringb1);
        //System.out.println(m.find());/this line is similar to the one below it
       // System.out.println(m.matches());//this line finds a valid mac address.
       
        
      System.out.println(hm.get(count)+" LOOK HERE");
     // System.out.println(hm.get(count-3)+" LOOK HERE");
  
        
          if(hm.get(count).equals(hm.get(count-3)))
          {
            //System.out.println(stringb1 + " You are setting this string to null!!");
            stringb1 = null;
            // System.out.println("MADE IT");
          }
        
        
      
        
    if(m.matches())
    {
      ita++;
      System.out.println("supposedly found a mac");
      
    }
    
    //System.out.println(hm.get(count));
   // System.out.println(hm.get(count-3));
    
   //if (stringb.find("^BC-30-5B-E1-3F-59$"))//ssn.matches("^([0-9A-F]{2}[:-]){5}([0-9A-F]{2})$"))//"^(\\d{2}-?\\d{2}-?\\d{2})-\\d{2}-?\\d{2}-\\d{2}-?\\d{2}-?\\D\\d$"))
  

        
     

     // System.out.println(hm.get(count));
      //  System.out.println(stringb1 + "Look to see if im next to white space!!!!");
     // System.out.println(hm.get(count));
     // System.out.println(hm.get(count-1));
        
        
         String last = stringb1;
         System.out.println(last);
      // String last = strings[1].toString();
    

       
        
     
        check++;
        ita++;
        itb++;
    
        generateCsvFile("C:\\Users\\user\\Desktop\\output.csv",last); 
        
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
 
   if (string!=null && string!="")
   { 
     writer.append(string);
     writer.append(',');
   }
          
    //  writer.write( string);
    // writer.append('\n');
 
     writer.flush();
     writer.close();
    
 }
 catch(IOException e)
 {
      e.printStackTrace();
 } 
    }
    
   
 }

 

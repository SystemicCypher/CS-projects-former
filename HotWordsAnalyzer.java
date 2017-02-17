//Austin Loza
//9715590
//austinloza@umail.ucsb.edu
package ProgAssignment2;

import java.io.IOException;
import java.lang.IllegalStateException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.NoSuchElementException;
import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;
import java.util.Arrays;
import java.util.Vector;


public class HotWordsAnalyzer {
        //Scanners to read the words from hotword and docs
        private static Scanner hotword, docs;
        //Makes filenames easier to type, and easier to print if desired
        private static String doc, hw; 
        //A map to pair the hotword with its count
        private static Map<String, Integer> words = new HashMap<String, Integer>();
        //A vector of all the hotwords in the exact order of appearance
        private static Vector<String> consec = new Vector<String>();
    
        //Constructor for HotWordsAnalyzer- reads the hotwords list and document to analyze and
        //detects and saves all hotwords, their counts, and their order
	public HotWordsAnalyzer (String hotWordsFileName, String docFileName){
            //Setting the filenames to the variables to make them easier to type
            doc = docFileName;
            hw = hotWordsFileName;
            
            //If opening of the file fails, an ioException will be thrown
		try{
                    hotword = new Scanner(Paths.get(hw));
                }
                catch (IOException ioException){
                    System.err.println("Error opening file. Terminating.");
                    System.exit(1);
                }
                
                try{
                    
                    docs = new Scanner(Paths.get(doc));
                }
                catch (IOException ioException){
                    System.err.println("Error opening file. Terminating.");
                    System.exit(1);
                }
                
                //Above opens both files
                
                //Goes through hotwords file and takes each word and pushes them to 
                //the map words so they can be used to locate the hotwords in the document
		try{
                    while(hotword.hasNext()){
                        String y;
                        String x = hotword.next();
                        y = x.toLowerCase();
                       //sets hotword as key and 0 for the count of that hotword in the document
                        words.put(y, 0);
                    }
                }
                //The element doesn't exist- file must not be a file
                catch(NoSuchElementException elementException){
                    System.err.println("Improper file. Terminating.");
                    System.exit(1);
                }
                //The file may not be readable or corrupt
                catch(IllegalStateException stateException){
                    System.err.println("Error reading from file. Terminating.");
                    System.exit(1);
                }
                
                //Above gets words and puts them into the words map
                try{
                    //reads the document and when it finds a hotword it increments the count in words
                    while(docs.hasNext()){
                        //gets next word
                        String x = docs.next();
                        String y = x.toLowerCase();
                        //Gets rid of the commas and periods
                        y = y.replace(",", "");
                        y = y.replace(".", "");
                        //If the word y is in the hotwords list
                        if(words.containsKey(y)){
                            //Adds to words map and increments count
                            consec.add(y);
                            int z;
                            z = words.get(y);
                            z++;
                            words.put(y, z);
                        }
                    }
                }
                catch(NoSuchElementException elementException){
                    System.err.println("Improper file. Terminating.");
                    System.exit(1);
                }
                catch(IllegalStateException stateException){
                    System.err.println("Error reading from file. Terminating.");
                    System.exit(1);
                }
                
                
		
	}
	
        //Returns the number of hotwords in the document
	public int count(){
		int sum = 0;
                for(Integer value: words.values()){
                    sum += value;
                }
                return sum;
	}
        
        //Returns the number of a particular hotword in the document
	public int count( String hotWord ){
            String x = hotWord.toLowerCase();
            //If the word is a hotword then get the count and return it
            if(words.containsKey(x)){
                return words.get(x);
            }
            //If not, then return -1
            else{
                return -1;
            }
	}
        
        //Returns the number of different hotwords in the document
	public int distinctCount(){
            int distinct = 0;
            //Loop through each key in words
            for(String key: words.keySet()){
                //If they appear in the file
                if(words.get(key) != 0){
                    //count it
                    distinct++;
                }
            }
            return distinct;
	}
	
        //Returns an array of the count number of top hotwords
        //E.g: the top 3 most frequently used hotwords
	public String[] topHotWords( int count ){
            //If the number put in the arguments is greater than the number of distinct hotwords
            //in the document, limit it to distinctCount
            if (count > distinctCount()){
                count = distinctCount();
            }
            //Creating the array that will hold all the hotwords in order of number of appearances 
            String[] topWord = new String[words.size()];
            //This is the subset of the array above that will return the amount specified by the count argument
            String[] output = new String[count];
            //Fills the array with blank strings
            Arrays.fill(topWord, "");
            //Iterator for moving through topWord for assignment
            int iterator = 0;
            //Loop through every hotword in words and puts those words in topWord
            for(String key: words.keySet()){
                topWord[iterator] = key;
                iterator++;
            }
            //Sorts the words in topword
            for(int i = 0; i < words.size(); i++){
                for(int j = words.size()-1; j > 0; j-- ){
                    
                    if(count(topWord[j]) > count(topWord[i])){
                        String temp = topWord[i];
                        topWord[i] = topWord[j];
                        topWord[j] = temp;
                    }
                    
                }
            }
            //Does a secondary check to be certain all words are in proper appearance number order
            for(int i = words.size()-1; i >0; i--){
                if(count(topWord[i]) > count(topWord[i-1])){
                    String temp = topWord[i];
                    topWord[i] = topWord[i-1];
                    topWord[i-1] = temp;
                }
            }
            //Orders the words with the same number of appearances by order of appearance in the document
            for (int i = 0; i < words.size(); i++){
                for(int j = i+1; j < words.size(); j++){
                    if (count(topWord[i]) == count(topWord[j])){
                        if (consec.indexOf(topWord[j]) < consec.indexOf(topWord[i])){
                            String temp = topWord[i];
                            topWord[i] = topWord[j];
                            topWord[j] = temp;
                        }
                    }
                }
            }
            //Gets the subset requested for return
            for (int i = 0; i < count; i++){
                output[i] = topWord[i];
            }
            return output;
	}	
	
        //Finds all the hotwords right after a chosen hotword
	public String[] nextHotWords( String hotWord ){
            //Created vector to push the variable amount of hotwords before the one in the arguments
            Vector<String> output = new Vector<String>();
            //The output string array which is returned
            String[] out;
            //Turns the hotword to lowercase for it to be compatible anc checkable
            String chk = hotWord.toLowerCase();
            //Iterates through consec
            for (int i = 0; i < consec.size()-1; i++) {
                //If the hotword is found, the next hotword in the sequence is stored in output
                if(consec.get(i).equals(chk)){
                    output.add(consec.get(i+1));
                }
            }
            //Out is set to the size of the vector of all the next hotwords
            out = new String[output.size()];
            //Copies items to out
            for(int j = 0; j < output.size(); j++){
                out[j] = output.get(j);
            }
            return out;
	}
	
        
        //Finds all the hotwords right before a chosen hotword
	public String[] prevHotWords( String hotWord ){
            //Created vector to push the variable amount of hotwords before the one in the arguments
            Vector<String> output = new Vector<String>();
            //The output string array which is returned
            String[] out;
            //Turns the hotword to lowercase for it to be compatible anc checkable
            String chk = hotWord.toLowerCase();
            //Created iterator to move through indeces of consec
            int i = 0;
            //Loops through every hotword in consec
            for (String x : consec.subList(0, count())) {
                //if the hotword equals the argument hotword then go to the next check
                if(x.equals(chk)){
                    //As long as the iterator is greater than 1, reach to the previous hot word
                    //in the series and put it in the vector
                    if(i > 1){
                        output.add(consec.get(i-1));
                    }
                }
                i++;
            }
            //Set the out array to the size of the vector that has all the previous hotwords
            out = new String[output.size()];
            //Copy the items in
            for(int j = 0; j < output.size(); j++){
                out[j] = output.get(j);
            }
            
            return out;
	}
	
        //This checks if a set of hotwords are consecutive
        //If any of the words aren't a hotword, the method returns false
	public boolean consecutive( String... hotWords ){
            //Making the array lowercase
            String[] low = hotWords;
            for(int i = 0; i < low.length; i++){
                low[i] = low[i].toLowerCase();
            }
            //Loops through the array of every hotword in order
            for (int i = 0; i < consec.size(); i++){
                //If the first of the array matches one item in consecutive it checks to see if the 
                //rest follow
                if(consec.get(i).equals(low[0])){
                    for(int j = 0; j < low.length; j++){
                        //if there is any mismatch, it breaks to keep checking
                        if(!(consec.get(i+j).equals(low[j]))){
                            break;
                        }
                        //if there is a match on the last comparison then the hotwords must be consecutive and thus
                        //the method returns true
                        else if((consec.get(i+j).equals(low[j])) && (j == (low.length - 1))){
                            return true;
                        }
                    }
                }
            }
            //If everything has failed, then the methood will return false
            return false;
	}

        
        
        
       
        
}

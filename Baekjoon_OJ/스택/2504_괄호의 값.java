import java.util.Stack;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
   public static void main(String[] args) throws Exception{
      
	   Scanner sc = new Scanner(System.in);
	   
	   Stack <String> stack = new Stack<>();
	   boolean fail = false;
	   
	   String temp = sc.nextLine();
	   int size = temp.length();
	   for(int j = 0; j < size; j++) {
		   if(temp.charAt(j) == '(') {
			   stack.push("(");
		   }
		   else if(temp.charAt(j) == '[') {
			   stack.push("[");
		   }
		   else if(temp.charAt(j) == ')') {
			   // Invaild case
			   if(stack.empty()) {
				   fail = true;
				   break;
			   }
			   int val = 0;
			   // Vaild case
			   while(!stack.empty()&&stack.peek() != "(" && stack.peek() != "[") {
				   val += Integer.parseInt(stack.pop());
			   }
			   if(!stack.empty()) {
			   if(stack.peek() == "(") {
				   stack.pop();
				   if(val == 0)
					   stack.push("2");
				   else
					   stack.push(Integer.toString(2*val));
			   }
			   else {
				   fail = true;
				   break;
			   }
			   }  
		   }
		   else if(temp.charAt(j) == ']') {
			// Invaild case
			   if(stack.empty()) {
				   fail = true;
				   break;
			   }
			   int val = 0;
			   // Vaild case
			   while(!stack.empty()&&stack.peek() != "(" && stack.peek() != "[") {
				   val += Integer.parseInt(stack.pop());
			   }
			   if(!stack.empty()) {
			   if(stack.peek() == "[") {
				   stack.pop();
				   if(val == 0)
					   stack.push("3");
				   else
					   stack.push(Integer.toString(3*val));
			   }
			   else {
				   fail = true;
				   break;
			   }
			   }
		   }
	   }
	   //End of () Check
	   int size2 = stack.size();
	   int result = 0;
	   for(int j = 0; j < size2; j++) {
		   if(stack.peek() == "(" || stack.peek() == "[") {
			   fail = true;
			   break;
		   }
		   		
		   result += Integer.parseInt(stack.pop());
	   }

	   if(fail)
		   System.out.println(0);
	   else
		   System.out.println(result);
	   
   }
   
}
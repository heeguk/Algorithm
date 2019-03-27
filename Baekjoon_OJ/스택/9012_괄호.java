import java.util.Stack;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
   public static void main(String[] args) throws Exception{
      
	   Scanner sc = new Scanner(System.in);
	   
	   int line = sc.nextInt();
	   sc.nextLine();	   
	   
	   int num = 1;
	   
	   for(int i = 0; i < line; i++) {
		   Stack <Character> stack = new Stack<>();
		   boolean fail = false;
		   
		   String temp = sc.nextLine();
		   int size = temp.length();
		   for(int j = 0; j < size; j++) {
			   if(temp.charAt(j) == '(') {
				   stack.push('(');
			   }
			   else if(temp.charAt(j) == ')') {
				   if(stack.empty()) {
					   fail = true;
					   break;
				   }
				   stack.pop();  
			   }
		   }
		   //End of () Check
		   if(!stack.empty())
			   fail = true;

		   if(fail)
			   System.out.println("NO");
		   else
			   System.out.println("YES");
	   }
	   
   }
   
}
import java.util.Stack;
import java.util.Scanner;

public class Main {
   public static void main(String[] args){
      
	   Scanner sc = new Scanner(System.in);
	   Stack <Integer> stack = new Stack<>();
	   int line = sc.nextInt();
	   sc.nextLine();	   
	   
	   
	   for(int i = 0; i < line; i++) {
		   String temp = sc.nextLine();
		   String [] op = temp.split(" ");
		   
		   switch(op[0]) {
		   case "push":
			   stack.push(Integer.parseInt(op[1]));
			   break;
		   case "pop":
			   if(stack.empty())
				   System.out.println(-1);
			   else {
				   System.out.println(stack.peek());
				   stack.pop();
			   }
			   break;
		   case "top":
			   if(stack.empty())
				   System.out.println(-1);
			   else
				   System.out.println(stack.peek());
			   break;
		   case "empty":
			   if(stack.empty())
				   System.out.println(1);
			   else
				   System.out.println(0);
			   break;
		   case "size":
			   System.out.println(stack.size());
			   break;
		   }
	   }

   }
   
}
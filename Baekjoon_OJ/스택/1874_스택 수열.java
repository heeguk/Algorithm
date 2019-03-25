import java.util.Stack;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
   public static void main(String[] args) throws Exception{
      
	   Scanner sc = new Scanner(System.in);
	   Stack <Integer> stack = new Stack<>();
	   Queue<Character> answer = new LinkedList();
	   int line = sc.nextInt();
	   sc.nextLine();	   
	   
	   int num = 1;
	   boolean no = false;
	   for(int i = 0; i < line; i++) {
		   int temp = sc.nextInt();
		   
		   if(stack.empty()) {
			   //System.out.println("empty");
			   while(true) {
				   stack.push(num++);
				   answer.offer('+');
				   if(stack.peek() == temp) {
					   stack.pop();
					   answer.offer('-');
					   break;
				   }
				   if(stack.peek() > temp) {
					   no = true;
					   break;
				   }
				   //answer.push('+');
			   }
		   }
		   else {
			   while(true) {
				   if(stack.peek() == temp) {
					   stack.pop();
					   answer.offer('-');
					   break;
				   }
				   
				   if(stack.peek() > temp) {
					   no = true;
					   break;
				   }
				   
				   stack.push(num++);
				   answer.offer('+');
			   }
		   }
		   
		   if(no)
			   break;
		   
	   }
	   
	   if(!no) {
		   int size = answer.size();
		   for(int i = 0; i < size; i++) {
			   System.out.println(answer.peek());
			   answer.poll();
		   }
	   }
	   else {
		   System.out.println("NO");
	   }
   }
   
}
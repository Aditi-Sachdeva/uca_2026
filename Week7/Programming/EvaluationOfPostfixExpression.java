package Week7.Programming;

import java.util.Stack;

public class EvaluationOfPostfixExpression {
    public static void main(String[] args) {
        
        String s = "2 3 1 * + 9 -";
        System.out.println(evalPostfix(s));
    }

    public static int evalPostfix(String s){

        Stack<Integer> stack = new Stack<>();

        String[] expr = s.split(" ");

        for(String exp : expr){

            int a;
            int b;

            if(exp.equals("+")){
                a = stack.pop();
                b = stack.pop();
                stack.push(b + a);
            }
            else if(exp.equals("-")){
                a = stack.pop();
                b = stack.pop();
                stack.push(b - a);
            }
            else if(exp.equals("*")){
                a = stack.pop();
                b = stack.pop();
                stack.push(b * a);
            }
            else if(exp.equals("/")){
                a = stack.pop();
                b = stack.pop();
                stack.push(b / a);
            }
            else{
                stack.push(Integer.parseInt(exp));
            }
        }
        
        return stack.pop();
    }
}

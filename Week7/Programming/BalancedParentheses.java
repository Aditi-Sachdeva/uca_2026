package Week7.Programming;

import java.util.Stack;

public class BalancedParentheses {
    public static void main(String[] args) {
        
        String s1 = "[()]{}{()()}";
        System.out.println(isValid(s1));

        String s2 = "[()";
        System.out.println(isValid(s2));
    }

    public static boolean isValid(String s){

        Stack<Character> stack = new Stack<>();

        for(char ch : s.toCharArray()){

            if (ch == '(') {
                stack.push(')');
            }
            else if(ch == '['){
                stack.push(']');
            }
            else if(ch == '{'){
                stack.push('}');
            }
            else{
                if(stack.isEmpty() || stack.pop() != ch){
                    return false;
                }
            }
        }

        return stack.isEmpty();
    }
}
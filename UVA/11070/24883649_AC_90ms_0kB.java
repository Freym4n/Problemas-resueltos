import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Calendar;
import java.util.LinkedList;
import java.util.Locale;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	static char[] s;
	static int l,n;
	static Queue<String> lst_op = new LinkedList<String>();
	static Queue<Double> lst_num = new LinkedList<Double>();
	static Stack<Double> st = new Stack<Double>();
	
	static double gen_num() {
		StringBuilder num = new StringBuilder("");
		double d = 1.0;
		if (s[l] == '-') {
			d = -1.0;
			l++;
		} else if (s[l] == '+') {
			d = 1.0;
			l++;
		}
		while (l < n && s[l] != '+' && s[l] !=  '-' &&  s[l] != '*' && s[l] != '/') {
			num.append(s[l]);
			l++;
		}
		double result = Double.parseDouble(num.toString());
		result *= d;
		return result;
	}

	static void prepare() {
		l = 0;
		lst_num.add(gen_num());
		while (l < s.length) {
			lst_op.add(s[l]+"");
			l++;
			lst_num.add(gen_num());
		}
	}
	
	static double solve() {
		st.push(lst_num.poll());
		int size = lst_op.size();
		String op;
		for(int i = 0; i < size; i++) {
			op = lst_op.poll();
			if (op.equals("*")) {
				st.push(st.pop()*lst_num.poll());
			} else if(op.equals("/")) {
				st.push(st.pop()/lst_num.poll());
			} else if (op.equals("-")){
				st.push(lst_num.poll()*(-1.0));
				lst_op.add(op);
			} else {
				st.push(lst_num.poll());
				lst_op.add(op);
			}
		}
		double result = 0.0;
		while (!st.isEmpty()) {
			
			result += st.pop();
		}
		return result;
	}
		
	
	
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		//BufferedReader bf = new BufferedReader(new FileReader("input.txt"));
		String x;
		while(bf.ready()) {
			lst_op.clear();
			lst_num.clear();
			st.clear();
			x = bf.readLine();
			s = x.toCharArray();
			l = 0;
			n = s.length;
			prepare();
			System.out.printf(Locale.ENGLISH,"%.3f\n",solve());
		}
	}
}

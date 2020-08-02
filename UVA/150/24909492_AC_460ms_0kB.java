import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	static String days[] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
	static int months[] = {0,31,59,90,120,151,181,212,243,273,304,334};
	static int normal_m[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	static int leap_m[] = {31,29,31,30,31,30,31,31,30,31,30,31};
	static String m_name[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
	static int codigo_siglo[] = {6,4,2,0,6};
	static int codigo_mes[] =  {0,3,3,6,1,4,6,2,5,0,3,5};



	static int index_of(String x, String arr[]) {
		int n = arr.length;
		for (int i = 0; i < n; i++) {
			if (arr[i].equals(x)) return i;
		} return 0;
	}

	static int find_month(int days) {
		for (int i = 0; i < 10; i++) {
			if (days <= months[i+1]) return i;
		} return 11;
	}

	static int find_num_days(String fecha) {
		String[] date = fecha.split(" ");
		int day_of_month = Integer.parseInt(date[1]);
		String month = date[2];
		int days_month = index_of(month,m_name);
		days_month = months[days_month];
		int year = Integer.parseInt(date[3]);
		int result = (year-1600)*365 + days_month + day_of_month;
		int bisiestos  = (year-1600)/4 - ((year-1600)/100  - (year-1600)/400) + 1;
		if ((is_leap_gregorian(year)) && ((days_month + day_of_month) <= 60)) 	result--;
		if (day_of_month == 29 && month.equals("Febrary")) result --;
		result += bisiestos;
		return result;
	}

	static boolean is_leap_gregorian(int year) {
		return (year % 4 == 0 && (year%100 != 0 || year%400 == 0));
	}

	static boolean is_leap_julian(int year) {
		return year%4 == 0;
	}

	static boolean is_gregorian(String fecha) {
		// d + m + a%100 + a (a%100)/4 + s
		String linea[] = fecha.split(" ");
		int d = Integer.parseInt(linea[1]);
		int m = index_of(linea[2],m_name);
		int codigo_m;
		if (m == 0) {
			if (is_leap_gregorian(Integer.parseInt(linea[3]))) {
				codigo_m = 6;
			} else codigo_m = 0;
		} 
		else if (m == 1) {
			if (is_leap_gregorian(Integer.parseInt(linea[3]))) {
				codigo_m = 2;
			} else codigo_m = 3;
		} 
		else 	codigo_m = codigo_mes[m];
		int a = Integer.parseInt(linea[3])%100;
		int a_4 = a/4;
		int s = (Integer.parseInt(linea[3])-1600)/100;
		int suma = d + codigo_m + a + a_4 + codigo_siglo[s];
		suma %= 7;
		if (linea[0].equals(days[suma])) return true;
		return false;

	}

	static int days_diference(int total) {
		int dif = 10;
		int keys[] = {36585,73109,109633,182682};
		for (int i = 0; i < keys.length; i++) {
			if (total < keys[i]) return dif += i;
		}
		return 14;
	}

	static String convert_method(String fecha,int totales, int dx) {
		String[] date = fecha.split(" ");
		String day_of_week = date[0];
		int day_of_month = Integer.parseInt(date[1]);
		String month = date[2];
		int num_month = index_of(month,m_name);
		int dias_mes[];
		int year = Integer.parseInt(date[3]);
		if (dx > 0) { 
			if (is_leap_gregorian(year)) dias_mes = leap_m; 
			else dias_mes = normal_m;
		} else {
			if (is_leap_julian(year)) dias_mes = leap_m; 
			else dias_mes = normal_m;
		}
		int d = dx<0?-1:1;
		int before;
		while (dx != 0) {
			day_of_month+=d;
			if (day_of_month>dias_mes[num_month] || day_of_month == 0) {
				before = dias_mes[num_month];
				num_month += d;	
				if (num_month < 0 || num_month > 11) {
					year += d;
					if (num_month > 11) num_month = 0;
					else num_month = 11; 
				}
				if (day_of_month > before) {
					day_of_month = 1;
				} else day_of_month = dias_mes[num_month]; 

			}
			dx += (dx < 0?1:-1);
		}
		String result = day_of_week + " ";
		result += day_of_month + (d < 0?"* ":" ");
		result += m_name[num_month] + " ";
		result += year;
		return result;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		String fecha;
		int dias_totales,diference;
		boolean gregorian;
		while(!(fecha = bf.readLine()).equals("#")) {
			dias_totales = find_num_days(fecha);
			gregorian = is_gregorian(fecha);
			diference = days_diference(dias_totales);
			if (!gregorian) {
				System.out.println(convert_method(fecha, dias_totales, diference));
			} else  {
				System.out.println(convert_method(fecha,dias_totales,-diference));
			}
		}
	}
}

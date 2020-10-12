public class IsItTheFlag {

public static boolean isFlag(String str) {
	return str.hashCode() == -1096474469;
}

public static void main(String[] args) {

String flag = "--------";

if (isFlag(flag))
	System.out.println("You found it!");
else
	System.out.println("Try again :(");

	}
}
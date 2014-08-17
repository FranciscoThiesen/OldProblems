public class CollatzTestDrive {
	public static void main(String[] args){
		Collatz teste = new Collatz();

		System.out.print("\nNumero 1: ");
		teste.maiorSequencia(1);

		System.out.println("\nNumero 2: ");
		teste.maiorSequencia(2);

		System.out.println("\nNumero 3: ");
		teste.maiorSequencia(3);

		System.out.println("\nNumero 1:.000.000 ");
		teste.maiorSequencia(1000000);
	}
}
class Collatz{
	public int calcTamanhoSequencia(int numeroCollatz){
		int tamanhoSequencia = 0;
		while (numeroCollatz >=1){
				if (numeroCollatz%2 == 0 || numeroCollatz == 1){
					numeroCollatz = numeroCollatz/2;
				}
				else{
					numeroCollatz = 3*numeroCollatz + 1;
				}
				tamanhoSequencia++;
			}
		return tamanhoSequencia;
	}

	public void maiorSequencia(int extremo){
		int tamanhoMaiorSequencia = 0;
		int maiorNumeroMaiorSequencia = 0;
		int contadorSequencia = 1;
		while (contadorSequencia <= extremo){
			int tamanhoSequencia = calcTamanhoSequencia(contadorSequencia);
			contadorSequencia++;
			if (tamanhoSequencia > tamanhoMaiorSequencia){
				tamanhoMaiorSequencia = tamanhoSequencia;
				maiorNumeroMaiorSequencia = contadorSequencia - 1;
			}
		}
		System.out.print("A maior sequencia e a do numero " + maiorNumeroMaiorSequencia + " e tem ela tem " + tamanhoMaiorSequencia + " numeros.");
	}
}
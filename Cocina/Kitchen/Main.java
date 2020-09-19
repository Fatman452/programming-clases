package Kitchen;

public class Main {

	public static void main(String[] args) {
		// SOLO PUSE DOS ALIMENTOS EN EL MENU, claro se pueden poner hasta que se quiera
		// TODO Auto-generated method stub
		Comida pizza=new Comida("Pizza",20,1000);
		Ingredients[] ingredientsPizza=new Ingredients[8];
		ingredientsPizza[0]= new Ingredients("Salsa de tomate",50,200.5);
		ingredientsPizza[1]= new Ingredients("Queso mozarella",70,250.58);
		ingredientsPizza[2]= new Ingredients("Harina",200,100.0);
		ingredientsPizza[3]= new Ingredients("Huevos",120,100.0);
		ingredientsPizza[4]= new Ingredients("Sal",10,15.0);
		ingredientsPizza[5]= new Ingredients("Peperonni",50,50.0);
		ingredientsPizza[6]= new Ingredients("Aceite de olivo",20,20.0);
		ingredientsPizza[7]= new Ingredients("Levadura",15,20.0);
		pizza.setIngredients(ingredientsPizza,8);
		
		Comida Hamburguesa=new Comida("Hamburguesa",15,500);
		Ingredients[] ingredientsHam=new Ingredients[7];
		ingredientsHam[0]= new Ingredients("Carne Agnus",100,150.5);
		ingredientsHam[1]= new Ingredients("Queso",50,40.0);
		ingredientsHam[2]= new Ingredients("Lechuga",30,50.0);
		ingredientsHam[3]= new Ingredients("Tocino",30,30.0);
		ingredientsHam[4]= new Ingredients("Pepinillo",10,10.0);
		ingredientsHam[5]= new Ingredients("Cebolla",20,15.0);
		ingredientsHam[6]= new Ingredients("Aderezo",30,20.0);
		Hamburguesa.setIngredients(ingredientsHam,7);
		
		System.out.println("Nombre: "+ pizza.getNombre()+ " Tiempo de preparacion: "+ pizza.getPreparationTime()+" Min "+" Cantidad de ingredientes: "+ pizza.getAmountIngredients()+" Precio: "+pizza.getPrice());
		System.out.println("Ingredientes de la "+pizza.getNombre()+":");
		for(int i=0;i<pizza.getAmountIngredients();i++){
			System.out.println("Nombre: "+ingredientsPizza[i].getName()+" Gramos: "+ingredientsPizza[i].getAmountInGrams()+ " Precio: "+ingredientsPizza[i].getPriceIngredient());
			
		}
		System.out.println(" ");
		System.out.println("Nombre: "+ Hamburguesa.getNombre()+ " Tiempo de preparacion: "+ Hamburguesa.getPreparationTime()+" Min "+" Cantidad de ingredientes: "+ Hamburguesa.getAmountIngredients()+" Precio: "+Hamburguesa.getPrice());
		System.out.println("Ingredientes de la "+Hamburguesa.getNombre()+":");
		for(int i=0;i<Hamburguesa.getAmountIngredients();i++){
			System.out.println("Nombre: "+ingredientsHam[i].getName()+" Gramos: "+ingredientsHam[i].getAmountInGrams()+ " Precio: "+ingredientsHam[i].getPriceIngredient());			
		}

	}

	

}

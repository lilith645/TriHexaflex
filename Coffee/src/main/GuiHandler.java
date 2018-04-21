package main;

public class GuiHandler {

	public static void main(String[] args) {
		// No model class initialised here, it's a singleton
		// Controller class is linked via FXML
		
		System.out.println(".....");
		// Launch GUI from the view
		GuiView.launch(GuiView.class);
		System.out.println(".....");
	}
}

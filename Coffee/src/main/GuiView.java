package main;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class GuiView extends Application {
	private static GuiView instance;
	private static Stage stage;

	public GuiView() {
		System.out.println("Initialised GuiView.");
	}

	/**
	 * Enables other classes to access methods within this class, once the program has been launched.
	 * 
	 * @return an instance of the GuiView class.
	 */
	public static GuiView getInstance() {
		if (instance == null) {
			instance = new GuiView();
		}
		return instance;
	}

	/**
	 * Loads the GUI.
	 */
	@Override
	public void start(Stage primaryStage) throws Exception {
		stage = primaryStage;

		// Load the fxml file
		FXMLLoader loader = new FXMLLoader(this.getClass().getResource("/gui.fxml"));

		// Set up the scene/stage
		Scene scene = new Scene(loader.load());//, 600, 320);
		primaryStage.setScene(scene);

		primaryStage.setResizable(false);
//		primaryStage.setMinWidth(800D);


		// Set Window Title
//		primaryStage.setTitle("Weather Station");

		// Display the GUI
		primaryStage.show();
	}
}

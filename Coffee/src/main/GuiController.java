package main;

import java.net.URL;
import java.util.ResourceBundle;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.*;
import javafx.scene.image.ImageView;
import javafx.scene.input.KeyCode;
import javafx.scene.layout.AnchorPane;

public class GuiController implements Initializable {

	@FXML
	private AnchorPane searchResults;
	@FXML
	private AnchorPane loadingScreen;
	@FXML
	private AnchorPane friendResult;
	@FXML
	private AnchorPane home; 
	@FXML
	private AnchorPane homeSearch;
	
	@FXML
	private Button photoBtn;
	
	@FXML
	private TextField searchBar;
	
	@FXML
	private ImageView searchImg;

	/**
	 * Fake reset
	 */
	@FXML
	private void returnHome() {
		searchResults.setVisible(false);
		friendResult.setVisible(false);
		searchBar.clear();
	}

	/**
	 * Launch photo taking spree
	 */
	@FXML
	private void takeSneakyShot() {
		//Take photo
		//Do Machine Learning stuff (compare photo)
		
	}
	 
	/**
	 * Find person by name 
	 */
	@FXML
	private void searchByName() {
		System.out.println(searchBar.getText()); 
		
		// Launch DB query
//		loadingScreen.setVisible(true); //rip
		searchResults.setVisible(true);
	}
	
	@FXML
	private void imageSelected() {
		System.out.println("Selected: " + searchBar.getText());
		friendResult.setVisible(true);
	}

	@Override
	public void initialize(URL fxmlFileLocation, ResourceBundle resources) {
		// Setting up file selection
	}
	
	
}
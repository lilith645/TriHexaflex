package main;

import java.net.URL;
import java.util.ResourceBundle;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;

public class GuiController implements Initializable {

	@FXML
	private Button photoBtn;


	/**
	 * Ensures that you cannot download with a file chosen.
	 */
	@FXML
	public void takeSneakyShot() {
		photoBtn.setDisable(true);
	}



	@Override
	public void initialize(URL fxmlFileLocation, ResourceBundle resources) {
		// Setting up file selection
	}
}
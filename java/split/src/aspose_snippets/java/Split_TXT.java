package aspose_snippets.java;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;

public class Split_TXT {
    public static void Execute() throws IOException {
        String pathSource = "../../TestData/test.txt";
        var pdfEditor = new com.aspose.pdf.facades.PdfFileEditor();

        var doc = new com.aspose.pdf.Document(pathSource, new com.aspose.pdf.TxtLoadOptions());
        //save input text to pdf to file
        doc.save("test.pdf", com.aspose.pdf.SaveFormat.Pdf);

        ByteArrayInputStream[] pages = pdfEditor.splitToPages("test.pdf");
        int index = 1;

        for(var ms : pages)
        {
            var page = new com.aspose.pdf.Document(ms);
            var textAbsorber = new com.aspose.pdf.TextAbsorber();
            page.getPages().accept(textAbsorber);
            String extractedText = textAbsorber.getText();
            Files.writeString(Path.of("text_"+ Integer.toString(index)+".txt"), extractedText);
            index++;
        }
    }
}

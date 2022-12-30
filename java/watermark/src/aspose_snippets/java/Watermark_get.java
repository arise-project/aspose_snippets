package aspose_snippets.java;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;

public class Watermark_get {
    public static void Execute() throws IOException {
            String pathSource = "../../TestData/test_with_watermark.pdf";
            var doc = new com.aspose.pdf.Document(pathSource);

            if(doc.getPages().get_Item(1).getArtifacts().get_Item(1).getSubtype() == com.aspose.pdf.Artifact.ArtifactSubtype.Watermark)
            {
                var fs = new FileOutputStream("test.jpg");
                doc.getPages().get_Item(1).getArtifacts().get_Item(1).getImage().save(fs);
                fs.flush();
                fs.close();
            }
    }
}

package aspose_snippets.java;

public class Watermark_remove {
    public static void Execute() {
            String pathSource = "../../TestData/test_with_watermark.pdf";
            var doc = new com.aspose.pdf.Document(pathSource);

            if(doc.getPages()[1].getArtifacts()[1].setSubtype(com.aspose.pdf.artifact.ArtifactSubtype.Watermark))
            {
                doc.getPages()[1].getArtifacts().Delete(doc.getPages()[1].getArtifacts()[1]);
            }

            //save result pdf to file
            doc.Save("test.pdf", com.aspose.pdf.SaveFormat.Pdf);
    }
}

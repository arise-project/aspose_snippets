package aspose_snippets.java;

public class Watermark_remove {
    public static void Execute() {
            String pathSource = "../../TestData/test_with_watermark.pdf";
            var doc = new com.aspose.pdf.Document(pathSource);

            if(doc.getPages().get_Item(1).getArtifacts().get_Item(1).getSubtype() == com.aspose.pdf.Artifact.ArtifactSubtype.Watermark)
            {
                doc.getPages().get_Item(1).getArtifacts().delete(doc.getPages().get_Item(1).getArtifacts().get_Item(1));
            }

            //save result pdf to file
            doc.save("remove_watermark.pdf", com.aspose.pdf.SaveFormat.Pdf);
    }
}

package aspose_snippets.java;

public class Watermark_add {
    public static void Execute() {
		        String pathSource = "../../TestData/test.pdf";
            String watermarkSource = "../../TestData/test.jpg";
            var doc = new com.aspose.pdf.Document(pathSource);

            var artifact = new com.aspose.pdf.WatermarkArtifact();
            artifact.setImage(watermarkSource);

            artifact.setArtifactHorizontalAlignment(com.aspose.pdf.HorizontalAlignment.Center);
            artifact.setArtifactVerticalAlignment(com.aspose.pdf.VerticalAlignment.Center);
            artifact.setRotation(15);
            artifact.setOpacity(1);
            artifact.setBackground(true);
            doc.getPages().get_Item(1).getArtifacts().add(artifact);

            //save result pdf to file
            doc.save("add_watermark.pdf", com.aspose.pdf.SaveFormat.Pdf);
    }
}

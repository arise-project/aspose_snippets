package aspose_snippets.java;

public class Watermark_add {
    public static void Execute() {
		        String pathSource = "../../TestData/test.pdf";
            String watermarkSource = "../../TestData/test.jpg";
            var doc = new com.aspose.pdf.Document(pathSource);

            var artifact = new com.aspose.pdf.WatermarkArtifact();
            artifact.SetImage(new FileStream(watermarkSource, FileMode.Open));

            artifact.set_ArtifactHorizontalAlignment(com.aspose.pdf.HorizontalAlignment.Center);
            artifact.set_ArtifactVerticalAlignment(com.aspose.pdf.VerticalAlignment.Center);
            artifact.set_Rotation(15);
            artifact.set_Opacity(1);
            artifact.set_IsBackground(true);
            doc.getPages()[1].getArtifacts().Add(artifact);

            //save result pdf to file
            doc.Save("test.pdf", com.aspose.pdf.SaveFormat.Pdf);
    }
}

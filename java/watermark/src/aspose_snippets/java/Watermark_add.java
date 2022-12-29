package aspose_snippets.java;

public class Watermark_add {
    public static void Execute() {
		const string pathSource = "../../TestData/test.pdf";
            const string watermarkSource = "../../TestData/test.jpg";
            var doc = new Aspose.Pdf.Document(pathSource);

            var artifact = new Aspose.Pdf.WatermarkArtifact();
            artifact.SetImage(new FileStream(watermarkSource, FileMode.Open));

            artifact.ArtifactHorizontalAlignment = Aspose.Pdf.HorizontalAlignment.Center;
            artifact.ArtifactVerticalAlignment = Aspose.Pdf.VerticalAlignment.Center;
            artifact.Rotation = 15;
            artifact.Opacity = 1;
            artifact.IsBackground = true;
            doc.Pages[1].Artifacts.Add(artifact);

            //save result pdf to file
            doc.Save("test.pdf", Aspose.Pdf.SaveFormat.Pdf);
    }
}

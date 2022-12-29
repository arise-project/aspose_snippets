package aspose_snippets.java;

public class Watermark_remove {
    public static void Execute() {
const string pathSource = "../../TestData/test_with_watermark.pdf";
            var doc = new Aspose.Pdf.Document(pathSource);

            if(doc.Pages[1].Artifacts[1].Subtype == Aspose.Pdf.Artifact.ArtifactSubtype.Watermark)
            {
                doc.Pages[1].Artifacts.Delete(doc.Pages[1].Artifacts[1]);
            }

            //save result pdf to file
            doc.Save("test.pdf", Aspose.Pdf.SaveFormat.Pdf);
    }
}

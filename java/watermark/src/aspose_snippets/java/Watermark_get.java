package aspose_snippets.java;

public class Watermark_get {
    public static void Execute() {
            const string pathSource = "../../TestData/test_with_watermark.pdf";
            var doc = new com.aspose.pdf.Document(pathSource);

            if(doc.getPages()[1].getArtifacts()[1].setSubtype(com.aspose.pdf.artifact.ArtifactSubtype.Watermark))
            {
                var fs = new FileStream("test.jpg",FileMode.Create);
                doc.Pages[1].Artifacts[1].Image.Save(fs);
                fs.Flush();
            }
    }
}

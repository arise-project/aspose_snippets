
doc = new Aspose.Pdf.Document("1.pdf");

if(doc.Pages[1].Artifacts[1].Subtype == Aspose.Pdf.Artifact.ArtifactSubtype.Watermark)
{
    fs = new FileStream("get_watermark.jpg",FileMode.OpenOrCreate);
    doc.Pages[1].Artifacts[1].Image.Save(fs);
}

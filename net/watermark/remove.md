
doc = new Aspose.Pdf.Document("1.pdf");

if(doc.Pages[1].Artifacts[1].Subtype == Aspose.Pdf.Artifact.ArtifactSubtype.Watermark)
    doc.Pages[1].Artifacts.Delete(doc.Pages[1].Artifacts[1]);

//save result pdf to file
doc.Save("remove_watermark.pdf", Aspose.Pdf.SaveFormat.Pdf);
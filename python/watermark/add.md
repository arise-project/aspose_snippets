
doc = aspose.pdf.Document("1.pdf")

artifact = aspose.pdf.WatermarkArtifact()
artifact.SetImage("1.jpg")

artifact.ArtifactHorizontalAlignment = aspose.pdf.HorizontalAlignment.Center
artifact.ArtifactVerticalAlignment = aspose.pdf.VerticalAlignment.Center
artifact.Rotation = 15
artifact.Opacity = 1
artifact.IsBackground = True
doc.Pages[1].Artifacts.Add(artifact)

#save result pdf to file
doc.Save("add_watermark.pdf", aspose.pdf.SaveFormat.PDF)
    
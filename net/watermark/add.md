```cs

doc = new Aspose.Pdf.Document("1.pdf");

artifact = new Aspose.Pdf.WatermarkArtifact();
artifact.SetImage(new FileStream("1.jpg", FileMode.Open));

artifact.ArtifactHorizontalAlignment = Aspose.Pdf.HorizontalAlignment.Center;
artifact.ArtifactVerticalAlignment = Aspose.Pdf.VerticalAlignment.Center;
artifact.Rotation = 15;
artifact.Opacity = 1;
artifact.IsBackground = true;
doc.Pages[1].Artifacts.Add(artifact);

//save result pdf to file
doc.Save("add_watermark.pdf", Aspose.Pdf.SaveFormat.Pdf);

```
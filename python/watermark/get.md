
doc = aspose.pdf.Document("1.pdf")

if doc.Pages[1].Artifacts[1].Subtype == aspose.pdf.Artifact.ArtifactSubtype.Watermark:
	fs = open("get_watermark.jpg", 'wc')
 	doc.Pages[1].Artifacts[1].Image.Save(fs)
  	fs.flush()
   	fs.close()
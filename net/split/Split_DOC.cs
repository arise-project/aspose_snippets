//using Aspose.Words;

namespace aspose_snippets.net
{
    public static partial class Split
    {
        public static void DOC()
        {
            // var pathSource = @"..\..\TestData\test.doc";
            // using (var fs = new FileStream(pathSource, FileMode.Open, FileAccess.Read))
            // {
            //     var doc = new Document(fs);
            //     Document result = (Document)doc.Clone(false);
            //     var lookup = new Dictionary<int, IList<Node>>();
            //     var nodeStartPageLookup = new Dictionary<Node, int>();
            //     var nodeEndPageLookup = new Dictionary<Node, int>();

            //     foreach (Node node in doc.GetChildNodes(NodeType.Any, true))
            //     {
            //         // Headers/Footers follow sections. They are not split by themselves.
            //         if (node.NodeType == NodeType.HeaderFooter || node.GetAncestor(NodeType.HeaderFooter) != null)
            //         {
            //             continue;
            //         }

            //         int startPage = nodeStartPageLookup.ContainsKey(node)
            //            ? nodeStartPageLookup[node]
            //            : collector.GetStartPageIndex(node);
            //         int endPage = GetPageEnd(node);
            //         for (int page = startPage; page <= endPage; page++)
            //         {
            //             if (!lookup.ContainsKey(page))
            //             {
            //                 lookup.Add(page, new List<Node>());
            //             }

            //             lookup[page].Add(node);
            //         }
            //     }
                
            //     foreach (var section in pageNumberFinder.RetrieveAllNodesOnPages(startIndex, endIndex, NodeType.Section))
            //     {
            //         result.AppendChild(result.ImportNode(section, true));
            //     }
            // }
        }
    }
}

// version 0.1
// json接口
var treeData = [{
    "text" : "",
    "nodes" : [{
        "text" : "",
        "nodes" : [
            {
                "text" : ""
            }
        ]
    }]
}];

function getData() {
    var texts = document.getElementById("val").value;
    // 按行分割
    var row = texts.split('\n');
    // "导师："，"级博士生："，"级硕士生："，"级本科生："和"、"
    // 导师
    var teacher = row[0].split("导师：");
    // 学生
    var len = row.length;
    //var degreeAndGrade = [];
    var nodes = [];
    for (var i = 1; i < len; i++)
    {
        // 按前后分割
        var information = row[i].split("：");
        // 前
        //degreeAndGrade.push(information[0]);
        // 后
        var stuName = information[1].split("、");
        var nameList = [];
        for (var j = 0; j < stuName.length; j++)
        {
            var name = stuName[j];
            nameList.push({ "text" : name });
        }
        nodes.push(
            {
                "text" : information[0],
                "nodes" : nameList
            }
        );
    }

    treeData[0]["text"] = teacher[1];
    treeData[0]["nodes"] = nodes;

    $('#tree').treeview({
        color: "#428bca",
        expandIcon: 'glyphicon glyphicon-chevron-right',
        collapseIcon: 'glyphicon glyphicon-chevron-down',
        emptyIcon: 'glyphicon glyphicon-user',
        showBorder: false,
        data: treeData
    });
}

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

from sklearn.manifold import TSNE
from sklearn.decomposition import PCA
from sklearn.decomposition import TruncatedSVD
from sklearn.discriminant_analysis import LinearDiscriminantAnalysis

from bokeh.layouts import row
from bokeh.plotting import figure, curdoc
from bokeh.layouts import column
from bokeh.models import ColumnDataSource, Button,  CDSView, IndexFilter
from bokeh.models.widgets import Slider, Select, TextInput

# 数据标签分离
data = pd.read_csv('mnistexcel.csv',header=None,dtype=np.float)
real_data = data.iloc[:,:-1].copy()
labels = np.squeeze(data.iloc[:,-1:].values)

# 增加手动标签列
res = data.copy()
res['new'] = 0

# pca预降维
pca = PCA(n_components=200)
data_pca = pca.fit_transform(real_data)

# svd预降维
svd = TruncatedSVD(n_components=200)
data_svd = svd.fit_transform(real_data)

# t-SNE 降维
x_embedded = TSNE(n_components=2).fit_transform(data_svd)
# x_embedded = TruncatedSVD(n_components=2).fit_transform(data_svd)

# 抽样 2% 标记样本
color = ['#ABABAB','black','green','red','blue','#FF7F50','brown','pink','#7D26CD','grey']
colors = np.repeat('white',5000)
# 之前的上色处理
for i in range(10):
    t = i*500 + (500*np.random.rand(10)).astype(int)
    colors[t] = color[i]


# bokeh 绘图
source = ColumnDataSource(data=dict(x=x_embedded[:,0], y=x_embedded[:,1], fill_color=colors))
source_add = ColumnDataSource(data=dict(x=[], y=[],id=[],fill_color=[]))
TOOLS="reset,lasso_select"
p = figure(tools=TOOLS,active_drag="lasso_select",plot_width=1000,plot_height=1000)
r = p.circle(x='x',y='y',source=source,fill_color='fill_color',size=5)
p2 = figure(tools=TOOLS,active_drag="lasso_select",plot_width=500,plot_height=500)
r_add = p2.circle(x='x',y='y',source=source_add,size=5)


# 图上分类作标记图
'''
max_len = np.max([np.max(x_embedded[:,0]),np.max(x_embedded[:,1])]).astype('int')
for i in range(10):
    arr = np.random.rand(10)*500
    for j in range(10):
        t = i*500+arr[j].astype('int')
        data_img = real_data.values[t][::-1].reshape(28,28)
        img = p.image(image=[data_img], x=[x_embedded[t,0]], y=[x_embedded[t,1]], dw=[max_len//40], dh=[max_len//40])
'''

# 回调函数和数据写入
def writeData(mark=-1,list_selected=[]):
    # global total
    # list_selected = np.intersect1d(list_selected, total)
    # total = np.setdiff1d(total,list_selected)
    res.iloc[list_selected,-1:] = mark
    res.to_csv('res.csv')

def callback1():
    selected = source.selected['1d']['indices']
    source_add.data = dict(x=x_embedded[selected,0],y=x_embedded[selected,1],id=selected)

def callback2():
    global colors
    selected = source.selected['1d']['indices']
    ca = int(category.value[2:])
    for i in selected:
        colors[i] = color[ca-1]
    source.data = dict(x=x_embedded[:,0],y=x_embedded[:,1], fill_color=colors)
    writeData(ca,selected)

# 选择插件及布局
n = np.shape(np.unique(labels))[0]
category = Select(title="类别",options=["类别%s" % (i+1) for i in range(n)],value="类别1")
button1 = Button(label="拆分")
button2 = Button(label="确定")
button1.on_click(callback1)
button2.on_click(callback2)

row_1 = column(category,button1,button2)
top = row(row_1,p2)
total = column(top,p)

# 总画布
curdoc().add_root(total)

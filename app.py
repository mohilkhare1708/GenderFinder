import pandas as pd
from flask import Flask, render_template, request
from sklearn.feature_extraction import DictVectorizer
import pickle

from sklearn.model_selection import train_test_split


app = Flask(__name__)


def features(name):
    name = name.lower()
    return {
        'FL': name[0],
        'F2L': name[0:2],
        'F3L': name[0:3],
        'LL': name[-1],
        'L2L': name[-2:],
        'L3L': name[-3:]
    }


model = pickle.load(open('DecisionTreeGenderClassifier.pkl', 'rb'))
df = pd.read_csv('dataset.csv')
names = df
dfX = features(names['name'])
dfy = names['sex']
dfX_train, dfX_test, dfy_train, dfy_test = train_test_split(dfX, dfy, test_size=0.25, random_state=42)


@app.route('/')
def home():
    return render_template('index.html')


@app.route('/predict/', methods=['POST'])
def predict():
    name = [str(x) for x in request.form.values()]
    print(name[0])
    dv = DictVectorizer()
    dv.fit_transform(dfX_train)
    transform_dv = dv.transform(features(name[0]))
    v = transform_dv.toarray()
    ans = model.predict(v)
    if ans == 0:
        op = "Female"
    else:
        op = "Male"
    print(op)
    return render_template('index.html', prediction_text='You would be most likely a {}'.format(op))


if __name__ == '__main__':
    app.run()

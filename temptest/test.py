import torch

print(torch.__version__)
print(torch.cuda.is_available())
a = torch.randn(2, 3)
print(a.type())
print(type(a))
print(isinstance(a, torch.FloatTensor))


def f(x=1):
    print(x)


f(2)